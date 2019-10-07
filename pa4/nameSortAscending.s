/*
 * Filename: nameSortAscending.s
 * Author: Adrian Jimenez
 * Userid: cs30xib
 * Description: sorts the name of the file in ascending order
 * Date:Dec. 4, 2013
 * Sources of Help: Discussion and tutors.
 */

 	.global		nameSortAscending! Declare the symbol to be globally
					! visible so we can call this function
					! from other modules.

	.section ".text"		! The text segment begins here

/*
 * Function name: nameSortAscending()
 * Function prototype: int nameSortAscending( const void *p1, const void *p2 );
 * Description: sorts the names of the files.
 * Parameters:
 *	arg 1: the first pointer to a file name
 *	arg 2: the second pointer to a file name
 * Side Effects: 
 * Error Conditions:
 * Return Value: zero if the pointer are equal, positive if first pointer
 *               is larger, and negative otherwise.
 * Registers Used:
 *	%i0 - arg 1 -- the first pointer
 *	%i1 - arg 2 -- the second pointer
 *
 */

nameSortAscending:

	save	%sp, -96, %sp	! save caller's window

	mov	%i0, %o0	! copy of the 1st arg
	mov	%i1, %o1	! copy of the 2nd arg
	call	strcmp		! calls the strcmp function
	nop

	mov	%o0, %i0	! copies return value to %i0

	ret		! returns from subroutine
	restore		! restores caller's window
