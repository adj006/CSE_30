/*
 * Filename: teststrToLong.c
 * Author: Adrian Jimenez
 * Userid: cs30xib
 * Description: Unit test program for function strToLong().
 * Date: Oct. 16, 2013
 * Sources of Help: testcheckRange.c file
 */

#include <limits.h>     /* For LONG_MIN and LONG_MAX */
#include "pa1.h"        /* For strToLong() function prototype */
#include "test.h"       /* For TEST() macro and stdio.h */

/*
 * long strToLong( char* str, int base );
 *
 * Returns the long value.
 *
 * Precondition: none.
 */

void
teststrToLong()
{
  printf( "Testing strToLong()\n" );

  /* Test strings with characters */
  TEST( strToLong( "1", 2) == 1);
  TEST( strToLong( "01", 8) == 1);
  TEST( strToLong( "1", 10) == 1);
  TEST( strToLong( "0x1", 16) == 1);

  /* Test */
  TEST( strToLong( "101", 2) == 5);
  TEST( strToLong( "0665", 8) == 437);
  TEST( strToLong( "437", 10) == 437);
  TEST( strToLong( "0x1B5", 16) == 437);
  TEST( strToLong( "", 16) == 437);



  printf( "Finished running tests on strToLong()\n" );
}

int
main()
{
  teststrToLong();

  return 0;
}
