/*
 * Filename: testset.c
 * Author: Adrian Jimenez
 * Userid: cs30xib
 * Description: This file tests the set() function.
 * Date: Oct. 27, 2013
 * Sources of Help:
 */

#include "test.h"   /* For TEST() macro and stdio.h */
#include <stdlib.h> /* For rand() function prototype */
#include <limits.h> /* For LONG_MIN and LONG_MAX */
#include "pa2.h"    /* For set() function prototype */

void
testset()
{
  unsigned int mask[2];
  //unsigned int bank0 = 0x1;
  //unsigned int bank1 = 0x1;

  printf( "Testing set()\n" );
  mask[0] = 0x0;
  mask[1] = 0x0;
  
  set( mask, 0x1, 0x1 );
  TEST( mask[0] == 0x1 && mask[1] == 0x1 );

  set( mask, 0x2, 0x2 );
  TEST( mask[0] == 0x3 && mask[1] == 0x3 );

  printf( "Finished running tests on set()\n" );

}

int
main()
{
  testset();

  return 0;
}
