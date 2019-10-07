/*
 * Filename: displayPermissions.c
 * Author: Adrian Jimenez
 * Userid: cs30xib
 * Description: This routine prints out the various rwx permissions for the
 *              owner, group, and others.
 * Date: Nov. 23, 2013
 * Sources of Help: Discussion and tutors.
 */

#include "myls.h"

void displayPermissions( const mode_t mode )
{
  int perm = 0x0;
  perm = ( mode & S_IRWXU );
  perm = ( perm >> 6 );
  switch(perm)
  {
    case 0:
      (void)printf( "---" );
      break;
    case 1:
      (void)printf( "--x" );
      break;
    case 2:
      (void)printf( "-w-" );
      break;
    case 3:
      (void)printf( "-wx" );
      break;
    case 4:
      (void)printf( "r--" );
      break;
    case 5:
      (void)printf( "r-x" );
      break;
    case 6:
      (void)printf( "rw-" );
      break;
    case 7:
      (void)printf( "rwx" );
      break;
  }

  perm = ( mode & S_IRWXG );
  perm = ( perm >> 3 );

  switch(perm)
  {
    case 0:
      (void)printf( "---" );
      break;
    case 1:
      (void)printf( "--x" );
      break;
    case 2:
      (void)printf( "-w-" );
      break;
    case 3:
      (void)printf( "-wx" );
      break;
    case 4:
      (void)printf( "r--" );
      break;
    case 5:
      (void)printf( "r-x" );
      break;
    case 6:
      (void)printf( "rw-" );
      break;
    case 7:
      (void)printf( "rwx" );
      break;
  }

  perm = ( mode & S_IRWXO );

  switch(perm)
  {
    case 0:
      (void)printf( "---" );
      break;
    case 1:
      (void)printf( "--x" );
      break;
    case 2:
      (void)printf( "-w-" );
      break;
    case 3:
      (void)printf( "-wx" );
      break;
    case 4:
      (void)printf( "r--" );
      break;
    case 5:
      (void)printf( "r-x" );
      break;
    case 6:
      (void)printf( "rw-" );
      break;
    case 7:
      (void)printf( "rwx" );
      break;
  }
}
