/*
 * Filename: main.c
 * Author: Adrian Jimenez
 * Userid: cs30xib
 * Description: This is the main driver for the program
 * Date: Oct. 26, 2013
 * Sources of Help:
 */

#include "pa2.h"
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <stdbool.h>
#include <strings.h>

#define BASE 0

FILE *stdError = stderr;  // This is to globalize the stderr
//errno;  // Also globalizes the errno

int main( int argc, char *argv[] )
{
  errno = 0;

  int prompt;

  // Initial light banks all off
  unsigned int lightBank[ NUM_OF_BANKS ] = {0, 0};

  // The 2 light bank patterns
  unsigned long bank0;
  unsigned long bank1;

  // Variable to store checkCmd return value
  int cmd;

  // The array of allowed commands
  const char * const commandsAllowed[] = { COMMANDS, NULL };

  // stdin args
  char *cmdTok, *argOneTok, *argTwoTok;

  // holder for fgets()
  char buf[BUFSIZ];
  
  // the FILE pointer needed in fgets()
  FILE *in;
  
  // Turns off buffering in stdout
  (void)setvbuf( stdout, NULL, _IONBF, 0 );

  if( argc == 2 )
  {
    displayLights( lightBank );
    prompt = 0;
    in = fopen( argv[1], "r" );
    while( ( fgets( buf, BUFSIZ, in ) ) != NULL )
    {
      cmdTok = strtok( buf, TOKEN_SEPARATORS );
      argOneTok = strtok( NULL, TOKEN_SEPARATORS );
      argTwoTok = strtok( NULL, TOKEN_SEPARATORS );
      if( argOneTok != NULL )
      {
        bank0 = strToULong( argOneTok, BASE );
        if(errno != 0)
          continue; 
      }
      if( argTwoTok != NULL )
      {
        bank1 = strToULong( argTwoTok, BASE );
        if(errno != 0)
          continue;
      }
      cmd = checkCmd( cmdTok, commandsAllowed );
      if( cmd == SET )
      {
        if( argOneTok == NULL )
        {
          (void)fprintf( stderr, "\n\tArgument(s) required for this command. "
                                 "Type \"help\" for more info.\n\n" );
          continue;
        }
        else if( argTwoTok == NULL )
          (void)fprintf( stderr, "\n\tA 2nd argument is required "
                                 "for this command.\n\n" );
        else
        {
          set( lightBank, bank0, bank1 );
          displayLights(lightBank);
        }
      }
      else if( cmd == CLEAR )
      {
        if( argOneTok == NULL )
        {
          (void)fprintf( stderr, "\n\tArgument(s) required for this command. "
                                 "Type \"help\" for more info.\n\n" );
          continue;
        }
        else if( argTwoTok == NULL )
          (void)fprintf( stderr, "\n\tA 2nd argument is required "
                                 "for this command.\n\n" );
        else
        {
          clear( lightBank, bank0, bank1 );
          displayLights(lightBank);
        }
      }
      else if( cmd == TOGGLE )
      {
        if( argOneTok == NULL )
        {
          (void)fprintf( stderr, "\n\tArgument(s) required for this command. "
                                 "Type \"help\" for more info.\n\n" );
          continue;
        }
        else if( argTwoTok == NULL )
          (void)fprintf( stderr, "\n\tA 2nd argument is required "
                                 "for this command.\n\n" );
        else
        {
          toggle( lightBank, bank0, bank1 );
          displayLights(lightBank);
        }
      }
      else if( cmd == SHIFT )
      {
        if( argOneTok == NULL )
          (void)fprintf( stderr, "\n\tArgument(s) required for this command. "
                                 "Type \"help\" for more info.\n\n" );
        else
        {
          shift( lightBank, bank0 );
          displayLights(lightBank);
        }
      }
      else if( cmd == ROTATE )
      {
        if( argOneTok == NULL )
          (void)fprintf( stderr, "\n\tArgument(s) required for this command. "
                                 "Type \"help\" for more info.\n\n" );
        else
        {
          rotate( lightBank, bank0 );
          displayLights(lightBank);
        }
      }
      else if( cmd == RIPPLE )
      {
        if( argOneTok == NULL )
          (void)fprintf( stderr, "\n\tArgument(s) required for this command. "
                                 "Type \"help\" for more info.\n\n" );
        else
          ripple( lightBank, bank0 );
      }
      else if( cmd == HELP )
        (void)printf( "The available commands are:\n"
                      "\tset     bank0BitPattern bank1BitPattern\n"
                      "\tclear   bank0BitPattern bank1BitPattern\n"
                      "\ttoggle  bank0BitPattern bank1BitPattern\n"
                      "\tshift   shiftCount\n"
                      "\trotate  rotateCount\n"
                      "\tripple  rippleCount\n"
                      "\thelp\n"
                      "\tquit\n" );
      else if( cmd == QUIT )
        return 0;
      else
        (void)fprintf( stderr, "\n\tBad command. Type \"help\" "
                               "for more info.\n\n" );
    }
  }
  // Prints the usage of the program
  else if( argc > 2 )
  {
    (void)fprintf( stderr, "\n\tUsage: %s [filename]\n\n", argv[0] ); 
  }
  displayLights( lightBank );
  prompt = 1;
  in = stdin;
  for( DISPLAY_PROMPT; fgets( buf, BUFSIZ, in ) != NULL; DISPLAY_PROMPT )
  {
    // Check the command
    cmdTok = strtok( buf, TOKEN_SEPARATORS );
    argOneTok = strtok( NULL, TOKEN_SEPARATORS );
    argTwoTok = strtok( NULL, TOKEN_SEPARATORS );
    if( argOneTok != NULL )
    {
      bank0 = strToULong( argOneTok, BASE );
      if(errno != 0)
        continue; 
    }
    if( argTwoTok != NULL )
    {
      bank1 = strToULong( argTwoTok, BASE );
      if(errno != 0)
        continue;
    }
    cmd = checkCmd( cmdTok, commandsAllowed );
    if( cmd == SET )
    {
      if( argOneTok == NULL )
      {
        (void)fprintf( stderr, "\n\tArgument(s) required for this command. "
                               "Type \"help\" for more info.\n\n" );
        continue;
      }
      else if( argTwoTok == NULL )
      {
        (void)fprintf( stderr, "\n\tA 2nd argument is required "
                               "for this command.\n\n" );
        continue;
      }
      else
      {
        set( lightBank, bank0, bank1 );
        displayLights(lightBank);
      }
    }
    else if( cmd == CLEAR )
    {
      if( argOneTok == NULL )
      {
        (void)fprintf( stderr, "\n\tArgument(s) required for this command. "
                               "Type \"help\" for more info.\n\n" );
        continue;
      }
      else if( argTwoTok == NULL )
        (void)fprintf( stderr, "\n\tA 2nd argument is required "
                               "for this command.\n\n" );
      else
      {
        clear( lightBank, bank0, bank1 );
        displayLights(lightBank);
      }
    }
    else if( cmd == TOGGLE )
    {
      if( argOneTok == NULL )
      {
        (void)fprintf( stderr, "\n\tArgument(s) required for this command. "
                               "Type \"help\" for more info.\n\n" );
        continue;
      }
      else if( argTwoTok == NULL )
        (void)fprintf( stderr, "\n\tA 2nd argument is required "
                               "for this command.\n\n" );
      else
      {
        toggle( lightBank, bank0, bank1 );
        displayLights(lightBank);
      }
    }
    else if( cmd == SHIFT )
    {
      if( argOneTok == NULL )
      {
        (void)fprintf( stderr, "\n\tArgument(s) required for this command. "
                               "Type \"help\" for more info.\n\n" );
        continue;
      }
      else
      {
        shift( lightBank, bank0 );
        displayLights(lightBank);
      }
    }
    else if( cmd == ROTATE )
    {
      if( argOneTok == NULL )
        (void)fprintf( stderr, "\n\tArgument(s) required for this command. "
                               "Type \"help\" for more info.\n\n" );
      else
      {
        rotate( lightBank, bank0 );
        displayLights(lightBank);
      }
    }
    else if( cmd == RIPPLE )
    {
      if( argOneTok == NULL )
        (void)fprintf( stderr, "\n\tArgument(s) required for this command. "
                               "Type \"help\" for more info.\n\n" );
      else
        ripple( lightBank, bank0 );
    }
    else if( cmd == HELP )
      (void)printf( "The available commands are:\n"
                     "\tset     bank0BitPattern bank1BitPattern\n"
                     "\tclear   bank0BitPattern bank1BitPattern\n"
                     "\ttoggle  bank0BitPattern bank1BitPattern\n"
                     "\tshift   shiftCount\n"
                     "\trotate  rotateCount\n"
                     "\tripple  rippleCount\n"
                     "\thelp\n"
                     "\tquit\n" );
    else if( cmd == QUIT )
      return 0;
    else
      (void)fprintf( stderr, "\n\tBad command. Type \"help\" "
                             "for more info.\n\n" );
  } 
  return 0;
}
