/*
 * Filename: set.s
 * Author: Adrian Jimenez
 * Userid: cs30xib
 * Description: This function sets the lights based on which bits are set
 *              the bit patterns specified.
 * Date: Oct. 27, 2013
 * Sources of Help:
 */

 	.global		set	! Declare the symbol to be globally visible
				! so we can call this function from other
				! modules.
	.section	".data"	! The Data segment begins here
	.section	".text"	! The text segment begins here

/*
 * Function name: set()
 * Function prototype: void set( unsigned int lightBank[],
 *                               const unsigned int bank0,
 *                               const unsigned int bank1 );
 * Desription: Sets the lights to the specified bit patterns.
 * Parameters:
 *	arg 1: unsigned int lightBank[] -- the light bank array
 *	arg 2: const unsigned int bank0 -- the pattern for the 1st bank
 *	arg 3: const unsigned int bank1 -- the pattern for the 2nd bank
 * Side Effects: Sets the specified lights.
 * Error Conditions: check if has valid bit pattern.
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

 set:

 	save	%sp, -96, %sp	! Save caller's window; if different than -96
				! then comment on how that value was calculated.

	ld	[%i0], %l0	! %l0 = lightBank[0]
	ld	[%i0 + 4], %l1	! %l1 = lightBank[1]
	or	%l0, %i1, %l2	! or op to light to set specified light
	or	%l1, %i2, %l3	! or op to light to set specified light
	st	%l2, [%i0]	! store back into memory
	st	%l3, [%i0 + 4]	! store back into memory

	ret			! Return from subroutine
	restore			! Restore caller's window; in "ret" delay slot

