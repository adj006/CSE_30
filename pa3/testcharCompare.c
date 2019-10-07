/*
 * Filename: testcharCompare.c
 * Author: Adrian Jimenez
 * Userid: cs30xib
 * Description: This program will test the charCompare() method.
 * Date: Nov. 18, 2013
 * Sources of Help: Discussion and tutors.
 */

#include "test.h"   /* For TEST() macro and stdio.h */
#include <stdlib.h> /* For rand() function prototype */
#include <limits.h> /* For LONG_MIN and LONG_MAX */
#include "anagrams.h"    /* For charCompare() function prototype */

void
testcharCompare()
{
  void * ptr1;
  void * ptr2;

  (void)printf( "Testing charCompare()\n" );
  ptr1 = "hello";
  ptr2 = "hello";

  TEST( charCompare( ptr1, ptr2 ) == 0 );

  (void)printf( "Finished running tests on charCompare()\n" );
}

int
main()
{
  testcharCompare();

  return 0;
}
