/*
 * Filename: strToLong.c
 * Author: Adrian Jimenez
 * Userid: cs30xib
 * Description: This file converts a string to a long
 * Date: Oct. 12, 2013
 * Source of Help: discussion
 */

#include "pa1.h"
#include <stdlib.h>
#include <errno.h>
#include <stdio.h>

long strToLong(char *str, int base)
{
  char *endptr;		// Local variable declaration
  char errMsg[BUFSIZ];  // error message
  errno = 0;
  long num = strtol(str, &endptr, base);   // Pass address of endptr to strtol()
  // If there is an error print the error message
  if (errno != 0)
  {
    (void)snprintf( errMsg, BUFSIZ, "\n\tConverting \"%s\" base \"%d\"",\
 str, base );
    perror( errMsg );
    return -1;
  }
  // If there is an error print the error message
  if(*endptr != 0)
  {
    (void)fprintf( stderr, "\n\t\"%s\" is not an integer\n", str );
    errno = -1;
    return -1;
  }
  return num; // no error return the value
}
