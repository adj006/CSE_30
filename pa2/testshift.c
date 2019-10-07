/*
 * Filename: testshift.c
 * Author: Adrian Jimenez
 * Userid: cs30xib
 * Description: This file tests the shift() function.
 * Date: Oct. 28, 2013
 * Sources of Help:
 */

#include "test.h"   /* For TEST() macro and stdio.h */
#include <stdlib.h> /* For rand() function prototype */
#include <limits.h> /* For LONG_MIN and LONG_MAX */
#include "pa2.h"    /* For shift() function prototype */

void
testshift()
{
  unsigned int mask[2];
  //int sh

  printf( "Testing shift()\n" );

  mask[0] = 0x1;
  mask[1] = 0x1;

  shift( mask, 1 );
  TEST( mask[0] == 0x2 && mask[1] == 0x2 );
  shift( mask, -1 );
  TEST( mask[0] == 0x1 && mask[1] == 0x1 );
  shift( mask, -1 );
  TEST( mask[0] == 0x0 && mask[1] == 0x80000000 );
  shift( mask, 5 );
  //printf("%d",mask[0]);
  //printf("%d",mask[1]);
  TEST( mask[0] == 0x10 && mask[1] == 0x0 );

  printf( "Finished running tests on shift()\n" );

}

int
main()
{
  testshift();

  return 0;
}
