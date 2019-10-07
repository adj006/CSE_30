/*
 * Filename: testdisplayLights.c
 * Author: Adrian Jimenez
 * Userid: cs30xib
 * Description: This file tests the displayLights() function.
 * Date: Oct. 28, 2013
 * Sources of Help:
 */

#include "test.h"   /* For TEST() macro and stdio.h */
#include <stdlib.h> /* For rand() function prototype */
#include <limits.h> /* For LONG_MIN and LONG_MAX */
#include "pa2.h"    /* For displayLights() function prototype */

void
testdisplayLights()
{

  printf( "Testing displayLights()\n" );

  unsigned int mask[2] = {0x1, 0x2};
  printf( "diplaying lights 0x1 and 0x2\n" );
  displayLights(mask);
  //TEST();

  printf( "Finished running tests on displayLights()\n" );

}

int
main()
{
  testdisplayLights();

  return 0;
}
