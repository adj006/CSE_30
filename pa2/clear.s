/*
 * Filename: clear.s
 * Author: Adrian Jimenez
 * Userid: cs30xib
 * Description: This function clears the lights based on which bits are set in
 *              the bit patterns specified.
 * Date: Oct. 26, 2013
 * Sources of Help:
 */

	.global		clear	! Declare the symbol to be globally visible
				! so we can call this function from other
				! modules.
	.section	".data"	! the data segment begins here
	.section	".text"	! the text segment begins here

/*
 * Function name: clear()
 * Function prototype: void clear( unsigned int lightBank[], 
 *                                 const unsigned int bank0,
 *                                 const unsigned int bank1 );
 * Description: Clears the lights to the specified bit patterns.
 * Parameters:
 *	arg 1: unsigned int lightBank[] -- the light bank array
 *	arg 2: const unsigned int bank0 -- the pattern for the 1st bank
 *	arg 3: const unsigned int bank1 -- the pattern for the 2nd bank
 * Side Effects: clears the specified lights.
 * Error Conditions: checks if has valid bit pattern.
 * Return Value: None
 * Registers Used:
 *	%i0 - arg 1
 *	%i1 - arg 2
 *	%i2 - arg 3
 *
 *	%l0 - address of lightBank[0]
 *	%l1 - address of lightBank[1]
 *	%l2 - address of bank0
 *	%l3 - address of bank1
 */

clear:

	save	%sp, -96, %sp	! Save caller's window; if different than -96
				! then comment on how that value was calculate.

	ld	[%i0], %l0	! %l0 = lightBank[0]
	ld	[%i0 + 4], %l1	! %l1 = lightBank[1]
	not	%i1		! flips all the '1's and '0's
	and	%l0, %i1, %l0	! and op to light bank with pattern 1
	st	%l0, [%i0]	! store it back into memory
	not	%i2		! flips all the '1's and '0's
	and	%l1, %i2, %l1	! and op to light bank with pattern 2
	st	%l1, [%i0 + 4]	! store it back into memory

	ret			! Return from subroutine
	restore			! Restore caller's window; in "ret" delay slot
