/*
 * Filename: testtoggle.c
 * Author: Adrian Jimenez
 * Userid: cs30xib
 * Description: This file tests the toggle() function.
 * Date: Oct. 28, 2013
 * Sources of Help:
 */

#include "test.h"   /* For TEST() macro and stdio.h */
#include <stdlib.h> /* For rand() function prototype */
#include <limits.h> /* For LONG_MIN and LONG_MAX */
#include "pa2.h"    /* For toggle() function prototype */

void
testtoggle()
{
  unsigned int mask[2];

  printf( "Testing toggle()\n" );

  mask[0] = 0x1;
  mask[1] = 0x1;

  toggle( mask, 0x1, 0x1 );
  TEST( mask[0] == 0 && mask[1] == 0 );

  mask[0] = 0xF;
  mask[1] = 0xF;

  toggle( mask, 0x5, 0x5 );
  TEST( mask[0] == 0xA && mask[1] == 0xA );

  toggle( mask, 0x5, 0x5 );
  TEST( mask[0] == 0xF && mask[1] == 0xF );

  printf( "Finished running tests on toggle()\n" );

}

int
main()
{
  testtoggle();

  return 0;
}
