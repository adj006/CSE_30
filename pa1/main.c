/*
 * Filename: main.c
 * Author: Adrian Jimenez
 * Userid: cs30xib
 * Description: This is the main driver for the program
 * Sources of Help: pa1.pdf file, tutors
 */

#include "pa1.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main( int argc, char *argv[] )
{
  errno = 0;
  bool valid = true;
  // Prints the usage of the program
  if( argc != 5 )
  {
    (void)fprintf( stderr, "\nUsage: %s width height border_ch diamond_ch\n",\
                   argv[0] );
    (void)fprintf( stderr, "    width \t(must be odd within the range of\
 [%d - %d])\n", WIDTH_MIN, WIDTH_MAX );
    (void)fprintf( stderr, "    height \t(must be odd within the range of\
 [%d - %d])\n", HEIGHT_MIN, HEIGHT_MAX );
    (void)fprintf( stderr, "\t\t(must be less than width)\n" );
    (void)fprintf( stderr, "    border_ch \t(must be an ASCII value within the\
 range [%d - %d])\n", ASCII_MIN, ASCII_MAX );
    (void)fprintf( stderr, "\t\t(must be different than diamond_ch\n" );
    (void)fprintf( stderr, "    diamond_ch \t(must be an ASCII value within the\
 , range [%d - %d])\n", ASCII_MIN, ASCII_MAX );
    (void)fprintf( stderr, "\t\t(must be different than border_ch\n" );
    (void)fprintf( stderr, "\n" );
    return -1;
  }
  long width = strToLong(*++argv, BASE);
  // If no error
  if( errno == 0 )
  {
    if( checkRange(width, WIDTH_MIN, WIDTH_MAX) == 0 )
    {
      valid = false;
      (void)fprintf( stderr, "\n\twidth(%ld) must be within the range of\
 [%d - %d]\n", width, WIDTH_MIN, WIDTH_MAX );
    }
    if( isOdd(width) == 0 )
    {
      valid = false;
      (void)fprintf( stderr, "\n\twidth(%ld) must be an odd number.\n",\
  width );
    }
  }
  long height = strToLong(*++argv, BASE);
  // If no error
  if( errno == 0 )
  {
    if( checkRange(height, HEIGHT_MIN, HEIGHT_MAX) == 0 )
    {
      valid = false;
      (void)fprintf( stderr, "\n\theigth(%ld) must be within the range of\
 [%d - %d] \n", height, HEIGHT_MIN, HEIGHT_MAX );
    }
    if( isOdd(height) == 0 )
    {
      valid = false;
      (void)fprintf( stderr, "\n\theight(%ld) must be an odd number. \n",\
 height );
    }
  }
  if( width < height )
  {
    valid = false;
    (void)fprintf( stderr, "\n\theight(%ld) must be less than width(%ld)\n",\
 height , width );
  }
  long border_ch = strToLong(*++argv, BASE);
  // If no error
  if( errno == 0 )
  {
    if( checkRange(border_ch, ASCII_MIN, ASCII_MAX) == 0 )
    {
      valid = false;
      (void)fprintf( stderr, "\n\tborder_ch(%ld) must be an ASCII code in the\
 range [%d - %d]\n", border_ch, ASCII_MIN, ASCII_MAX );
    }
  }
  long diamond_ch = strToLong(*++argv, BASE);
  // If no error
  if( errno == 0 )
  {
    if( checkRange(diamond_ch, ASCII_MIN, ASCII_MAX) == 0 )
    {
      valid = false;
      (void)fprintf( stderr, "\n\tdiamond_ch(%ld) must be an ASCII code in the\
 range [%d - %d]\n", diamond_ch, ASCII_MIN, ASCII_MAX );
    }
  }
  if( border_ch == diamond_ch )
  {
    valid = false;
    (void)fprintf( stderr, "\n\tborder_ch(%ld) and diamond_ch(%ld) must be\
 different\n" , border_ch, diamond_ch );
  }
  // If no errors display the diamond
  if( valid )
    displayDiamond( width, height, border_ch, diamond_ch );
  else
  {
    (void)fprintf( stderr, "\n" );
    return -1;	// An error occured
  }
  return 0;	// Successful exit
}
