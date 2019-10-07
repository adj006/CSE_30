/*
 * Filename: strToLong.c
 * Author: Adrian Jimenez
 * Userid: cs30xib
 * Description:
 * Date: Oct. 12, 2013
 * Source of Help:
 */

#include "pa1.h"
#include <stdlib.h>
#include <errno.h>
#include <stdio.h>

long strToLong(char *str, int base)
{
  char *endptr;		// Local variable declaration
  char errMsg[BUFSIZ];
  (void)snprintf( errMsg, BUFSIZ, "Converting \"%s\" base \"%d\"", str, base );
  errno = 0;
  long num = strtol(str, &endptr, base);	// Pass address of endptr to strtol()
  if (errno != 0)
    perror( "errMsg: Result too large" );
  if(*endptr != 0)
    fprintf( stderr, "\"%s\" is not an integer", str );
  errno = 0;
  return num;
}

