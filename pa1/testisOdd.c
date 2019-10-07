/*
 * Filename: testisOdd.c
 * Userid: cs30xib
 * Description: Test for isOdd()
 * Date: Oct. 15, 2013
 * Sources of Help: testcheckRange.c file
 */

#include <stdlib.h>	/* For rand() function prototype */
#include <limits.h>	/* For LONG_MIN and LONG_MAX */
#include "pa1.h"	/* For isOdd() function prototype */
#include "test.h"	/* For TEST() macro and stdio.h */

/*
 * int isOdd( long num );
 *
 * Returns 1 if value is within minRange and maxRange, inclusive.
 * Returns 0 otherwise.
 *
 * Precondition: Assume minRange is less than or equal to maxRange.
 */

void
testisOdd()
{
  printf( "Testing isOdd()\n" );

  /* Test around 0. */
  TEST( isOdd( 0 ) == 0 );
  TEST( isOdd( 1 ) != 0 );

  /* Test around a positive */
  TEST( isOdd( 99 ) != 0 );
  TEST( isOdd( 100 ) == 0 );
  TEST( isOdd( 101 ) != 0 );
  TEST( isOdd( 102 ) == 0 );

  /* Test MAX int values */
  TEST( isOdd( LONG_MAX ) != 0 );

  printf( "Finished running tests on isOdd()\n" );
}

int
main()
{
  testisOdd();

  return 0;
}
