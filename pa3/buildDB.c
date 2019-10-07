/*
 * Filename: buildDB.c
 * Author: Adrian Jimenez
 * Userid: cs30xib
 * Description: This function builds the anagram database.
 * Date: Nov. 8, 2013
 * Sources of Help: Discussion and tutors.
 */

#include "anagrams.h"

/*
 * This function builds the anagram database
 */
void buildDB( const char * const dbFilename )
{
  FILE *inFilePtr, *outFilePtr;
  char charArray[SIZE] = {0};
  struct anagram anaStruct;
  //errno = 0;
  int i;
  char *tmp;
  int ch_len;
  size_t result;
  if( ( inFilePtr = fopen ( dbFilename, "r" ) ) == NULL )
  {
    perror ( dbFilename );
    exit ( EXIT_FAILURE );
  }
  //errno = 0;
  if( ( outFilePtr = fopen ( anagramsDB, "wb" ) ) == NULL )
  {
    perror ( anagramsDB );
    exit ( EXIT_FAILURE );
  }
  while( fgets ( charArray, SIZE, inFilePtr ) != NULL )
  {
    tmp = strchr ( charArray, '\n' );
    if(tmp != NULL)
      *tmp = '\0';
    (void)memset ( anaStruct.word, '\0', SIZE );
    (void)memset ( anaStruct.sorted, '\0', SIZE );
    ch_len = strlen(charArray);
    (void)strncpy ( anaStruct.word, charArray, SIZE );
    for( i = 0; i < ch_len; i++ )
      charArray[i] = (char)tolower(charArray[i]);
    qsort( charArray, ch_len, sizeof(char), charCompare );
    (void)strncpy ( anaStruct.sorted, charArray, SIZE );
    result = fwrite ( &anaStruct, sizeof(struct anagram), 1, outFilePtr );
    if( result == 0 )
      (void)fprintf( stderr, "Whoa! Got a write error on word \"%s\".\n",
               anaStruct.word );
    (void)memset(charArray, '\0', SIZE);
  }
  (void)printf("Anagram database file \"%s\" built.\n", anagramsDB);
  (void)fclose ( inFilePtr );
  (void)fclose ( outFilePtr );
}

