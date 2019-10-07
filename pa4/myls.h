/*
 * Filename: myls.h
 * Author: Adrian Jimenez
 * Userid: cs30xib
 * Description: This is the header file for the program.
 * Date: Nov. 23, 2013
 * Sources of Help: Discussion and tutors.
 */

#ifndef _MYLS_H // Macro Guard
#define _MYLS_H

#define AFLAG 0x1
#define LFLAG 0x2
#define RFLAG 0x4
#define TFLAG 0x8

#include <dirent.h>   /* To pick up MAXNAMLEN - maximum filename length */
#include <sys/stat.h> /* For struct stat definition */
#include <pwd.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/mkdev.h>
#include <stddef.h>
#include <errno.h>
#include <libgen.h>

struct fileInfo
{
  char name[MAXNAMLEN];
  struct stat stbuf;
};

int buildFileInfoTable( const char *filename,
                        struct fileInfo ** const tablePtr );

void displayFileInfo( struct fileInfo * const table, const int entries,
                      const int displayMode );

int mtimeSortAscending( const void *p1, const void *p2 );

int mtimeSortDescending( const void *p1, const void *p2 );

int nameSortAscending( const void *p1, const void *p2 );

int nameSortDescending( const void *p1, const void *p2 );

void displayPermissions( const mode_t mode );

void displayOwnerName( const uid_t uid );

void displayGroupName( const gid_t gid );

#endif  /* _MYLS_H */
