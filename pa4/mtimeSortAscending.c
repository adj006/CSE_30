/*
 * Filename: mtimeSortAscending.c
 * Author: Adrian Jimenez
 * Userid: cs30xib
 * Description: Sorts the file information in ascending order based on time.
 * Date: Dec. 3, 2013
 * Sources of Help: Discussion and tutors.
 */

#include "myls.h"

int mtimeSortAscending( const void *p1, const void *p2 )
{
  return  ((struct fileInfo*)p2)->stbuf.st_mtime - ((struct fileInfo*)p1)->stbuf.st_mtime ;
}
