/*
 * Filename: userInteractive.c
 * Author: Adrian Jimenez
 * Userid: cs30xib
 * Description: 
 * Date: Nov. 8, 2013
 * Sources of Help: Discussion and tutors.
 */

#include "anagrams.h"

void userInteractive( struct anagramInfo *anagramInfoPtr )
{
  char charArray[SIZE] = {0};
  struct anagram anaStruct;
  struct anagram *anaStructPtr;
  char *tmp = NULL;
  int ch_len = 0;
  (void)printf("Enter a word to search for anagrams [^D to exit]: ");
  while( fgets( charArray, SIZE, stdin ) != NULL )
  {
    tmp = (char*)strchr ( charArray, '\n' );
    if(tmp != NULL)
      *tmp = '\0';
    (void)memset ( anaStruct.word, '\0', SIZE );
    (void)memset ( anaStruct.sorted, '\0', SIZE );
    ch_len = strlen(charArray);
    (void)strncpy ( anaStruct.word, charArray, SIZE );
    for( int i = 0; i < ch_len; i++ )
      charArray[i] = (char)tolower(charArray[i]);
    qsort( charArray, ch_len, sizeof(char), charCompare );
    (void)strncpy ( anaStruct.sorted, charArray, SIZE );
    anaStructPtr = (struct anagram*)bsearch( &anaStruct,
                                             anagramInfoPtr->anagramPtr,
                                             anagramInfoPtr->numOfAnagrams,
                                             sizeof(struct anagram),
                                             sortedMemberCompare );
    if( anaStructPtr == NULL )
      (void)fprintf( stderr, "No anagrams found.\n");
    else
      (void)printf("Anagram(s) are:");
    while( ( anaStructPtr > anagramInfoPtr->anagramPtr ) && 
           ( strcmp( ( anaStructPtr - 1 )->sorted, charArray ) == 0 ) )
      anaStructPtr--;
    while( ( anaStructPtr < anagramInfoPtr->anagramPtr +
            (anagramInfoPtr->numOfAnagrams)*sizeof(struct anagram) ) &&
            ( strcmp( anaStructPtr->sorted, charArray ) == 0 ) )
    {
      (void)printf(" %s", anaStructPtr->word);
      anaStructPtr++;
    }
    (void)printf("Enter a word to search for anagrams [^D to exit]: ");
  }
}
