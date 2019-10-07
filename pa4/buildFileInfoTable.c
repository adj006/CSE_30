/*
 * Filename: buildFileInfoTable.c
 * Author: Adrian Jimenez
 * Userid: cs30xib
 * Description: Takes the file/directory name and the address of the pointer
                to struct fileInfo back in main() that we will fill in based
                on our dynamic building of this fileInfo table.
 * Date: Nov. 23, 2013
 * Sources of Help: Discussion and tutors.
 */

#include "myls.h"

int buildFileInfoTable(const char *filename, struct fileInfo ** const tablePtr)
{
  int entry = 0;
  struct stat s;
  DIR *dir;
  struct dirent *dp;
  struct fileInfo *fileInfoPtr = NULL;
  errno = 0;
  char path[MAXNAMLEN];
  if( (lstat( filename, &s ) != 0) || (errno != 0) )
  {
    (void)fprintf( stderr,  "lstat -- " );
    perror( filename );
    exit( EXIT_FAILURE );
  }
  if( (S_ISDIR(s.st_mode)) == 1 )
  {
    if( (dir = opendir(filename)) == NULL )
    {
      (void)fprintf( stderr, "opendir -- " );
      perror( filename );
      exit( EXIT_FAILURE );
    }
    (void)printf( "%s:\n", filename );
    while( (dp = readdir(dir)) != NULL )
    {
      errno = 0;
      (void)memset( path, '\0', MAXNAMLEN );
      (void)snprintf( path, MAXNAMLEN, "%s/%s", filename, dp->d_name );
      if( (lstat( path, &s ) != 0) || (errno != 0) )
      {
        (void)fprintf( stderr, "lstat -- " );
        perror( path );
        (void)closedir(dir);
        exit( EXIT_FAILURE );
      }
      fileInfoPtr = (struct fileInfo*)realloc( fileInfoPtr,
                                      (entry + 1)*sizeof(struct fileInfo) );
      if( fileInfoPtr == NULL )
      {
        (void)fprintf( stderr, "Trying to realloc another struct fileInfo"
                         "(in buildFileInfoTable())" );
        (void)fprintf( stderr, "Only partial info will be displayed.\n" );
        (void)closedir(dir);
        exit (-1);
      }
      (void)memset ( (fileInfoPtr + entry )->name, '\0', MAXNAMLEN );
      (void)strncpy ( (fileInfoPtr + entry)->name, dp->d_name, MAXNAMLEN );
      (fileInfoPtr + entry)->stbuf = s;
      *tablePtr = fileInfoPtr;
      entry++;
    }
    (void)closedir(dir);
  }
  else
  {
    fileInfoPtr = (struct fileInfo*)malloc( sizeof(struct fileInfo) );
    if( fileInfoPtr == NULL )
    {
      (void)fprintf( stderr, "Trying to malloc a struct fileInfo "
                             "(in buildFileInfoTable())" );
      exit (-1);
    }
    (void)memset ( fileInfoPtr->name, '\0', MAXNAMLEN );
    (void)strncpy ( fileInfoPtr->name, filename, MAXNAMLEN );
    fileInfoPtr->stbuf = s;
    *tablePtr = fileInfoPtr;
    entry++;
  }
  return entry;
}
