/*
 * Filename: anagrams.h
 * Author: Adrian Jimenez
 * Userid: cs30xib
 * Description: This is the header file for the program.
 * Date: Nov. 8, 2013
 * Sources of Help: Discussion and tutors.
 */

#ifndef ANAGRAMS_H // Macro Guard
#define ANAGRAMS_H

#define SIZE 80
#define anagramsDB "anagrams.dat"
#include <errno.h>
#include <stdlib.h>
#include <ctype.h>
//#include "globals.c"
#include <string.h>
#include <sys/stat.h>
#include <stdio.h>

struct anagram
{
  char word[SIZE];
  char sorted[SIZE];
};

struct anagramInfo
{
  struct anagram *anagramPtr;
  int numOfAnagrams;
};

void buildDB ( const char *const dictFilename);

void processDB ( struct anagramInfo *anagramInfoPtr );

void userInteractive ( struct anagramInfo * anagramInfoPtr );

int anagramCompare ( const void *ptr1, const void *ptr2 );

int sortedMemberCompare ( const void *ptr1, const void *ptr2 );

int charCompare ( const void *ptr1, const void *ptr2 );

#endif // ANAGRAMS_H
