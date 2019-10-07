/*
 * Filename: processDB.c
 * Author: Adrian Jimenez
 * Userid: cs30xib
 * Description: 
 * Date: Nov. 8, 2013
 * Sources of Help: Discussion and tutors.
 */
#include <sys/stat.h>
#include "anagrams.h"

/*
 * processes the database
 */
void processDB( struct anagramInfo *anagramInfoPtr )
{
  struct stat statStruct;
  FILE *inFilePtr;
  char err[SIZE];
  size_t result;
  if ( stat (anagramsDB, &statStruct) != 0 )
  {
    (void)fprintf( stderr, "Stat failed on anagram database file: " );
    perror(err);
    (void)fprintf( stderr, "May need to run \"anagrams --build dictionary_file\""
                       " first.\n" );
    exit( EXIT_FAILURE );
  }
  anagramInfoPtr->numOfAnagrams = statStruct.st_size/sizeof(struct anagram);
  anagramInfoPtr->anagramPtr = (struct anagram*)calloc(
                                                   anagramInfoPtr->numOfAnagrams,
                                                   sizeof(struct anagram) );
  if( anagramInfoPtr->anagramPtr == NULL )
  {
    (void)fprintf( stderr, "Trying to calloc() anagrams data structure in memory" );
    exit (1);
  }
  if( ( inFilePtr = fopen ( anagramsDB, "r" ) ) == NULL )
  {
    perror ( anagramsDB );
    exit ( EXIT_FAILURE );
  }
  result = fread ( anagramInfoPtr->anagramPtr, sizeof(struct anagram),
                   anagramInfoPtr->numOfAnagrams, inFilePtr );
  if( result != anagramInfoPtr->numOfAnagrams )
    (void)fprintf( stderr, "Error with fread() of anagram data.\n"
                       "Expecting %d; got %d.\n",
                       anagramInfoPtr->numOfAnagrams, result );
  qsort( anagramInfoPtr->anagramPtr, anagramInfoPtr->numOfAnagrams,
         sizeof(struct anagram), anagramCompare );
  (void)fclose ( inFilePtr );
}
