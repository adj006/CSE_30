/*
 * Filename: printBirthDateInfo.c
 * Author: Adrian Jimenez
 * Userid: cs30xib
 * Description: Example C routine to print out the birthday info
 *              (month day, year) using a pointer to a structure.
 *              called from main()
 * Date: Oct.2, 2013
 * Sources of Help: List all the people, books, websites, etc. that you
 *                  used to help you write the code in this source file.
 */

#include <stdio.h>
#include "pa0.h"

/*
 * Function name: printBirthDateInfo()
 * Function prototype:
 *   void printBirthDateInfo( struct birthDateInfo *bDayInfo );
 * Description: Prints to stdout the month, day, and year members of a
 *              struct birthDateInfo node.
 * Parameters:
 *     arg1: struct birthDateInfo *bDayInfo -- pointer to the
 *           birthDateInfo struct which should be printed.
 * Side Effects: Outputs the student's birthday info.
 * Error Conditions: Checks to make sure arg1 is not NULL.
 *                   No checks to ensure struct data are correct type/values.
 * Return Value: None.
 */


void
printBirthDateInfo( struct birthDateInfo *bDayInfoPtr )
{
  if ( bDayInfoPtr != NULL )
     (void) printf( "My birth date is: %s %d, %d\n",
                    bDayInfoPtr->month,
                    bDayInfoPtr->day,
                    bDayInfoPtr->year );
}
