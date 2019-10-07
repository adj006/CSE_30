/*
 * Filename: mtimeSortDescending.s
 * Author: Adrian Jimenez
 * Userid: cs30xib
 * Description: sorts the name of the file in descending order based on time
 * Date:Dec. 4, 2013
 * Sources of Help: Discussion and tutors.
 */

 	.global		mtimeSortDescending! Declare the symbol to be globally
					! visible so we can call this function
					! from other modules.

	.section ".text"		! The text segment begins here

/*
 * Function name: mtimeSortDescending()
 * Function prototype: int mtimeSortDescending( const void *p1, const void *p2 );
 * Description: sorts the names of the files.
 * Parameters:
 *	arg 1: the first pointer to a file name's time
 *	arg 2: the second pointer to a file name's time
 * Side Effects: 
 * Error Conditions:
 * Return Value: zero if the pointer are equal, positive if first pointer
 *               is larger, and negative otherwise.
 * Registers Used:
 *	%o0 - arg 1 -- the first pointer
 *	%o1 - arg 2 -- the second pointer
 *	%o2 - the value of the offset
 *            
 */

mtimeSortDescending:

	set	offset, %o2		! sets the offset to %o2
	ld	[%o2], %o2		! loads the value
	ld	[%o0 + %o2], %o0	! %o0 is now mtime of 1st ptr
	ld	[%o1 + %o2], %o1	! %o1 is now mtime of 2nd ptr

	sub	%o0, %o1, %o0		! to determine which is bigger

	retl		! returns from the subroutine
	nop
