/*
 * Filename: testcheckCmd.c
 * Author: Adrian Jimenez
 * Userid: cs30xib
 * Description: This file tests the checkCmd() function.
 * Date: Oct. 27, 2013
 * Sources of Help:
 */

#include "test.h"   /* For TEST() macro and stdio.h */
#include <stdlib.h> /* For rand() function prototype */
#include <limits.h> /* For LONG_MIN and LONG_MAX */
#include "pa2.h"    /* For checkCmd() function prototype */

void
testcheckCmd()
{
  const char * const cmdString;
  const char * const commands[] = {COMMANDS};

  printf( "Testing checkCmd()\n" );
  cmdString = "set";

  TEST( checkCmd( cmdString, commands ) == 0 );

  printf( "Finished running tests on checkCmd()\n" );
}

int
main()
{
  testcheckCmd();

  return 0;
}
