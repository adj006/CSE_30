/*
 * Filename: testsortedMemberCompare.c
 * Author: Adrian Jimenez
 * Userid: cs30xib
 * Description: This program will test the sortedMemberCompare() method.
 * Date: Nov. 18, 2013
 * Sources of Help: Discussion and tutors.
 */

#include "test.h"   /* For TEST() macro and stdio.h */
#include <stdlib.h> /* For rand() function prototype */
#include <limits.h> /* For LONG_MIN and LONG_MAX */
#include "anagrams.h"    /* For sortedMemberCompare() function prototype */

void
testsortedMemberCompare()
{
  struct anagram anagram1;
  struct anagram anagram2;

  struct anagram *anagramPtr1;
  struct anagram *anagramPtr2;

  (void)printf( "Testing sortedMemberCompare()\n" );

  anagramPtr1 = &anagram1;
  anagramPtr2 = &anagram2;

  (void)strncpy( anagram1.sorted, "opst", SIZE );
  (void)strncpy( anagram2.sorted, "opst", SIZE );

  TEST( sortedMemberCompare( anagramPtr1, anagramPtr2 ) == 0 );

  (void)printf( "Finished running tests on sortedMemberCompare()\n" );
}

int
main()
{
  testsortedMemberCompare();

  return 0;
}
