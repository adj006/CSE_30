/*
 * Filename: nameSortDescending.c
 * Author: Adrian Jimenez
 * Userid: cs30xib
 * Description: Sorts the names of the file in descending oreder.
 * Date: Dec. 3, 2013
 * Sources of Help: Discussion and tutors.
 */

#include "myls.h"

int nameSortDescending( const void *p1, const void *p2 )
{
  return strcmp( ((struct fileInfo*)p2)->name, ((struct fileInfo*)p1)->name );
}
