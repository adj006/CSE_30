/*
 * Filename: displayFileInfo.c
 * Author: Adrian Jimenez
 * Userid: cs30xib
 * Description: Checks to see if the table should be sorted by modification
 *              time (st_mtime)[-t option] and if so whether it should be
 *              sorted in reverse order of the [-r option]. Else we are
 *              displaying via defult alphabetic order on the name of the
 *              file so check to see if the -r flag had been specified to
 *              determine if the sort is reverse of the default. You will use
 *              qsort() to sort the entries in the table.
 * Date: Nov. 23, 2013
 * Sources of Help: Discussion and tutors.
 */

#include "myls.h"

void displayFileInfo( struct fileInfo * const table, const int entries,
                      const int displayMode )
{
  struct timeval currTime;
  (void)gettimeofday(&currTime, NULL);
  char * sTime;
  char * start;
  char * end;
  int i;
  if( (displayMode & TFLAG) )
  {
    if( (displayMode & RFLAG) )
      qsort( table, entries, sizeof(struct fileInfo), mtimeSortDescending );
    else
      qsort( table, entries, sizeof(struct fileInfo), mtimeSortAscending );
  }

  else if( (displayMode & RFLAG) )
    qsort( table, entries, sizeof(struct fileInfo), nameSortDescending );
  else
    qsort( table, entries, sizeof(struct fileInfo), nameSortAscending );
  if( !(displayMode & AFLAG) && !(displayMode & LFLAG) )
  {
    for( i = 0; i < entries; i++ )
    {
      if( basename((table + i)->name)[0] != '.' )
        (void)printf( "%s\n", (table + i)->name );
    }
  }
  if(( displayMode & AFLAG ) && !( displayMode & LFLAG )) 
  {
    for( i = 0; i < entries; i++ ) 
    {
      (void)printf( "%s\n", (table + i)->name );
    }
  }
  if( LFLAG & displayMode ) 
  {
    for( i = 0; i < entries; i++ ) 
    {
      if( basename((table + i)->name)[0] == '.' ) 
      {
         if( !( AFLAG & displayMode ))
            continue;
      }
      // Verify the mode of each entry member.
      if( S_ISDIR(((table + i)->stbuf).st_mode) ) 
      {
        (void)printf( "d" );
      }
      else if( S_ISLNK(((table + i)->stbuf).st_mode) ) 
      {
        (void)printf( "l" );
      }
      else if( S_ISBLK(((table + i)->stbuf).st_mode) ) 
      {
        (void)printf( "b" );
      }
      else if( S_ISCHR(((table + i)->stbuf).st_mode) ) 
      {
        (void)printf( "c" );
      }
      else 
      {
        (void)printf( "-" );
      }
      // Display permissions.
      (void)displayPermissions( ((table + i)->stbuf).st_mode );
      // Display number of links to the entry member.
      (void)printf( " %3lu ",((table + i)->stbuf).st_nlink );
      // Display user.
      displayOwnerName( ((table + i)->stbuf).st_uid );
      //Display group.
      displayGroupName( ((table + i)->stbuf).st_gid );
      // Verify if the entry member is character or block device.
      if( ((S_ISBLK((table + i)->stbuf.st_mode)) != 0) ||
          ((S_ISCHR((table + i)->stbuf.st_mode)) != 0) )
        (void)printf("%3ld, %3ld ", major(((table + i)->stbuf).st_rdev),
                                   minor(((table + i)->stbuf).st_rdev));
   
      else 
      {
        // Print the entry member size.
        (void)printf( "%7ld ", ((table + i)->stbuf).st_size );
      }
      // Get the file's last modification time.     
      time_t table_time = ( ((table + i)->stbuf).st_mtime );
      // If the file is modification more than 6 months.
      if( table_time > (time(NULL) - 15724800 )) 
      {
        sTime = ctime( &table_time );
        start = strchr( sTime, ' ' );
        end = strrchr( sTime, ':' );
        *end = '\0';
        (void)printf( "%s ", start + 1 );
      }
      else 
      {
        // or less than 6 months.
        sTime = ctime( &table_time );
        start = strchr( sTime, ' ' );
        end = strchr( sTime, ':' );
        end -= 3;
        char *str1 = strrchr( sTime, ' ' );
        char *str2 = strrchr( sTime, '\n' );
        *end = '\0';
        *str2 = '\0';
        (void)printf( "%s  %s ", start + 1, str1+1 );
      }
      (void)printf( "%s\n", (table + i)->name );
    }
  }
}
