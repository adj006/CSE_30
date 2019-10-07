/*
 * Filename: pa0.h
 * Author: Adrian Jimenez 
 * Userid: cs30xib
 * Description: Function prototypes and defines for PA0
 * Date: Sept. 28, 2013
 * Sources of Help: List all the people, books, websites, etc. that you 
 *                  used to help you write the code in this source file. 
 */

/* #defines used in PA0 */

#define NAME "Joe Jane Student"

/* User-defined types used in PA0 */

struct birthDateInfo
{
  char *month;
  unsigned int day;
  unsigned int year;
};

/* Function prototypes for the C and assembly routines used in PA0 */

void printHello( char *string );

void printBirthDateInfo( struct birthDateInfo *bDayInfo );

int sum3( int a, int b, int c ); 
