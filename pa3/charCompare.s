/*
 * Filename: charCompare.s
 * Author: Adrian Jimenez
 * Userid: cs30xib
 * Description: This program will do a comparison of two characters, passed
 *              by reference, that returns an integer; zero when they are
 *              equal, positive if 1st char is greater or negative otherwise.
 * Date: Nov. 8, 2013
 * Sources of Help: Discussion and tutors.
 */

	.global		charCompare	! Declare the symbol to be globally
					! visible so we can call this function
					! from other modules.

	.section ".text"		! The text segment begins here

/*
 * Function name: charCompare()
 * Function prototype: int charCompare( const void *ptr1, const void *ptr2 );
 * Description: compares two chars.
 * Parameters:
 *	arg 1: the first pointer to a char
 *	arg 2: the second pointer to a char
 * Side Effects: 
 * Error Conditions:
 * Return Value: zero if the pointer are equal, positive if first pointer
 *               is larger, and negative otherwise.
 * Registers Used:
 *	%i0 - arg 1 -- the first pointer
 *	%i1 - arg 2 -- the second pointer
 *
 *	%l0 - the value of the first pointer
 *	%l1 - the value of the second pointer
 *            
 */

charCompare:

 	save	%sp, -96, %sp	! Save caller's window; if different than -96
				! the comment on how that value was
				! calculated.

	ldub	[%i0], %l0	! %l0 = ptr1
	ldub	[%i1], %l1	! %l1 = ptr2

	cmp	%l0, %l1	! compares ptr1 with ptr2
	bg	pos		! branch to positive label
	nop

	cmp	%l0, %l1	! compares ptr1 with ptr2
	bl	neg		! branch to negative label
	nop

	mov	%g0, %i0	! sets the return value to zero

	ba	end		! branches to the end
	nop

pos:

	mov	1, %i0		! sets the return value to positive integer

	ba	end		! branches to the end
	nop

neg:

	mov	-1, %i0		! sets the return value to negative integer

end:

	ret			! Return from subroutine
	restore			! Restore caller's window; in "ret" delay slot
