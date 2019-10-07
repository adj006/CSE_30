/*
 * FileName: isOdd.s
 * Author: Adrian Jimenez
 * Userid: cs30xib
 * Description: This file checks if the value is odd
 * Date: Oct. 13, 2013
 * Sources of Help: tutors
 */

	.global isOdd		! Declares the symbol to be globally visible so
				! we can call this function from other modules.

	.section ".text"	! The text segment begins here

/*
 * Function name: isOdd()
 * Function prototype: int isOdd( long num );
 * Description: checks if it's odd
 * Parameters:
 *	arg 1: long num -- the number to be checked
 * Side Effects: outputs if it's odd
 * Error Conditions: no negative numbers
 * Return Value: 1 if it's odd 0 if not
 * Registers Used:
 *	%i0 - long num
 *	%o0 - long num
 *	%o1 - 2
 */

isOdd:
	save	%sp, -96, %sp	! Save caller's window; if different than -96
				! then comment on how that value was calculated.

	mov	%i0, %o0	! %o0 = num
	mov	2, %o1		! %o1 = 2
	call	.rem		! remainder of %o0 % %o1
	nop
	cmp	%o0, 1		! compares if rem with 1
	bne	end_if		! if not equal take branch
	nop

	mov	1,%i0 		! return value = 1
	ret			! Return from subroutine
	restore			! Restore caller's window; in "ret" delay slot



end_if:
	mov	0, %i0 		! return value = 0
	ret			! Return from subroutine
	restore			! Restore caller's window; in "ret" delay slot
