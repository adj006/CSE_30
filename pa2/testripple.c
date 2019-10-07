/*
 * Filename: testripple.c
 * Author: Adrian Jimenez
 * Userid: cs30xib
 * Description: This file tests the ripple() function.
 * Date: Oct. 28, 2013
 * Sources of Help:
 */

#include "test.h"   /* For TEST() macro and stdlib.h */
#include <stdlib.h> /* For rand() function prototype */
#include <limits.h> /* For LONG_MIN and LONG_MAX */
#include "pa2.h"    /* For ripple() function prototype */

void
testripple()
{
  unsigned int mask[2];

  printf( "Testing ripple()\n" );

  mask[0] = 0xFFCBA9A6;
  mask[1] = 0xF0F0F0E4;

  ripple( mask, 6 );
  ripple( mask, -6 );

  printf( "Finished running tests on ripple()\n" );

}

int
main()
{
  testripple();

  return 0;
}
