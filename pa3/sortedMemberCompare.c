/*
 * Filename: sortedMemberCompare.c
 * Author: Adrian Jimenez
 * Userid: cs30xib
 * Description: 
 * Date: Nov. 8, 2013
 * Sources of Help: Discussion and tutors.
 */

#include "anagrams.h"

/*
 * Compares the sorted member of the anagrams
 */
int sortedMemberCompare( const void *ptr1, const void *ptr2 )
{
  return strcmp( ((struct anagram*)ptr1)->sorted, ((struct anagram*)ptr2)->sorted );
}
