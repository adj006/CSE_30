/*
 * Filename: teststrToULong.c
 * Author: Adrian Jimenez
 * Userid: cs30xib
 * Description: This file tests the strToULong() function.
 * Date: Oct. 28, 2013
 * Sources of Help:
 */

#include "test.h"   /* For TEST() macro and stdio.h */
#include <stdlib.h> /* For rand() function prototype */
#include <limits.h> /* For LONG_MIN and LONG_MAX */
#include <errno.h>
#include "pa2.h"    /* For strToULong() function prototype */

FILE *stdError = stderr;

void
teststrToULong()
{

  printf( "Testing strToULong()\n" );

  TEST( strToULong( "1", 2 ) == 1 );
  TEST( strToULong( "01", 0 ) == 1 );
  TEST( strToULong( "1", 0 ) == 1 );
  TEST( strToULong( "0x1", 0 ) == 1 );

  TEST( strToULong( "110110101", 2 ) == 437 );
  TEST( strToULong( "0665", 0 ) == 437 );
  TEST( strToULong( "437", 0 ) == 437 );
  TEST( strToULong( "0x1B5", 0 ) == 437 );
  //TEST( strToULong( NULL, 0 ) == 0 );
  strToULong("9999999999999999999", 0);
  // printf("%d", errno);
  TEST(errno == 0);
  printf( "Finished running tests on strToULong()\n" );
  strToULong("123abc", 0);

}

int
main()
{
  teststrToULong();

  return 0;
}
