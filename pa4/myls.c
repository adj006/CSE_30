/*
 * Filename: myls.c
 * Author: Adrian Jimenez
 * Userid: cs30xib
 * Description: Checks for command-line options with getopt() and determines
 *              how to display the file information.
 * Date: Nov. 23, 2013
 * Sources of Help: Discussion and tutors.
 */

#include "myls.h"


int offset = offsetof( struct fileInfo, stbuf.st_mtime );

int main( int argc, char * argv[] )
{
  struct fileInfo *file;
  int i;
  int flag = 0x0;
  int entry = 0;
  while( (i = getopt( argc, argv, "alrt" )) != -1 )
  {
    switch(i)
    {
      case 'a':
        flag += AFLAG;
        break;
      case 'l':
        flag += LFLAG;
        break;
      case 'r':
        flag += RFLAG;
        break;
      case 't':
        flag += TFLAG;
        break;
      case '?':
        (void)fprintf( stderr, "Usage: %s [-alrt] [file ...]\n", argv[0] );
        exit(-1);
    }
  }
  if( optind == argc )
  {
    entry = buildFileInfoTable( ".", &file );
    if(entry != 0)
      (void)displayFileInfo( file, entry, flag );
    free(file);
  }
  else if( optind < argc )
  {
    for( i = optind; i < argc; i++ )
    {
      entry = buildFileInfoTable( argv[i], &file );
      if(entry != 0)
        (void)displayFileInfo( file, entry, flag );
      free(file);
    }
  }
  return 0;
}
