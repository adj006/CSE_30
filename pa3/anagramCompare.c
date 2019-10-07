/*
 * Filename: anagramCompare.c
 * Author: Adrian Jimenez
 * Userid: cs30xib
 * Description: This file compares the anagrams.
 * Date: Nov. 8, 2013
 * Sources of Help: Discussion and tutors.
 */

#include "anagrams.h"

/*
 * Compares the anagrams
 */
int anagramCompare( const void *ptr1, const void *ptr2 )
{
  if( strcmp( ((struct anagram*)ptr1)->sorted,
              ((struct anagram*)ptr2)->sorted ) == 0 )
    return strcmp( ((struct anagram*)ptr1)->word,
                   ((struct anagram*)ptr2)->word );
  return strcmp( ((struct anagram*)ptr1)->sorted,
                 ((struct anagram*)ptr2)->sorted );
}
