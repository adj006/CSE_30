/*
 * Filename: displayOwnerName.c
 * Author: Adrian Jimenez
 * Userid: cs30xib
 * Description: This routine will call getpwuid() to get a pointer to the 
 *              struct passwd for this uid so we can get the owner's name
 *              as a string (pw_name member). If the passwd entry cannot be
 *              found, just print the numeric value of the uid.
 * Date: Nov. 23, 2013
 * Sources of Help: Discussion and tutors.
 */

#include "myls.h"

void displayOwnerName( const uid_t uid )
{
  struct passwd *pwd;
  pwd = getpwuid(uid);
  if( pwd == NULL )
    (void)printf( "%-8u ", uid );
  else
    (void)printf( "%-8s ", pwd->pw_name );
}
