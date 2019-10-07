/*
 * Filename: checkRange.s
 * Author: Adrian Jimenez
 * Userid: cs30xib
 * Description: This file is to check if the value is within range
 * Date: Oct. 13, 2013
 * Sources of Help: notes and tutors
 */

	.global checkRange	! Declares the symbol to be globally visible so
				! we can call this function from other modules.

	.section ".text"	! The text segment begins here

/*
 * Function name: checkRange()
 * Description: This functions takes in 3 argumetents and determines if it is within the range
 * Parameters:
 *	arg 1: long value -- value to be tested
 *	arg 2: long minRange -- minumum range 
 *	arg 3: long maxRange -- maximum range
 * Side Effects: outputs if the value is within range
 * Error Conditions: if it is greater than the maxRange and less than the
 *                   minRange
 * Return Value: returns 1 is valid, 0 if not
 * Registers Used:
 *	%i0 - arg 1 -- the value to be checked
 *	%i1 - arg 2 -- the min range
 *	%i2 - arg 3 -- the max range
 */

checkRange:
	save	%sp, -96, %sp	! Save caller's window; if different than -96
				! then comment on how that value was calculated.
	cmp	%i0, %i1	! compares value with the min range
	bl	end_if		! if it is less than then goto end_if
	nop			! Delay slot for call instruction

	cmp	%i0, %i2	! compares value with the max range
	bg	end_if		! if greater than then goto end_if
	nop			! Delay slot for call instruction

	mov	1, %i0		! %i0 = 1
	ret			! Return from subroutine
	restore			! Restore caller's window; in "ret" delay slot


end_if:
	mov	0, %i0		! % i0 = 0
	ret			! Return from subroutine
	restore			! Restore caller's window; in "ret" delay slot
