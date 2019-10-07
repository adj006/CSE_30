/*
 * Filename: checkCmd.c
 * Author: Adrian Jimenez
 * Userid: cs30xib
 * Description: This function checks to see if the first token on the line
 *              passes as cmdString is one of the bit commands defined for
 *              this lightboard controlling program listed in commands.
 * Date: Oct. 26, 2013
 * Sources of Help:
 */

#include "pa2.h"
#include <string.h>

/*
 * 
 */
int checkCmd( const char * const cmdString, const char * const commands[] )
{
  int i;
  for( i = 0; i <= QUIT; i++ )
  {
    if( strcmp( cmdString, commands[i] ) == 0 )
    {
      return i;
    }
  }
  return -1;
}
