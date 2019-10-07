/*
 * Filename: testclear.c
 * Author: Adrian Jimenez
 * Userid: cs30xib
 * Description: This file tests the clear() function
 * Date: Oct. 27, 2013
 * Sources of Help:
 */

#include "test.h"   /* For TEST() macro and stdio.h */
#include <stdlib.h> /* For rand() function prototype */
#include <limits.h> /* For LONG_MIN and LONG_MAX */
#include "pa2.h"    /* For clear() function prototype */

void
testclear()
{
  unsigned int mask[2];
 // unsigned int mask1[2];
  const unsigned int bank0 = 0x1;
  const unsigned int bank1 = 0x1;

  printf( "Testing clear()\n" );
  mask[0] = 0x1;
  mask[1] = 0x1;

  clear( mask, bank0, bank1);
  TEST( mask[0] == 0 && mask[1] == 0 );

  mask[0] = 0xF;
  mask[1] = 0xF;

  clear( mask, 0x5, 0x5 );
  TEST( mask[0] == 0xA && mask[1] == 0xA );

  printf( "Finished running tests on clear()\n" );
  
}

int
main()
{
  testclear();

  return 0;
}
