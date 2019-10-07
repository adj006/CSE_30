/*
 * Filename: toggle.s
 * Author: Adrian Jimenez
 * Userid: cs30xib
 * Description: This function toggles the lights based on which bits are set
 *              in the bit patterns specified.
 * Date: Oct. 27, 2013
 * Sources of Help:
 */

 	.global		toggle		! Declare the symbol to be globally
					! visible so we can call this function
					! from other modules.
	.section	".data"		! The data segment begins here

	.section	".text"		! The text segment begins here

/*
 * Function Name: toggle()
 * Function Prototype: void toggle( unsigned int lightBank[],
 *                                  const unsigned int bank0,
 *                                  const unsigned int bank1 );
 * Description: toggles the lights.
 * Parameters:
 *	arg 1: unsigned int lightBank[] -- the array of light banks
 *	arg 2: const unsigned int bank0 -- the bit pattern for the 1st bank
 *	arg 3: const unsigned int bank1 -- the bit pattern for the 2nd bank
 * Side Effects: toggles the lights.
 * Error Conditions:
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

toggle:

	save	%sp, -96, %sp	! Save caller's window; if different than -96
				! then comment on how that value was calculated.

	ld	[%i0], %l0	! %l0 = lightBank[0]
	ld	[%i0 + 4], %l1	! %l1 = lightBank[1]
	xor	%l0, %i1, %l0	! xor op to light bank with pattern 1
	st	%l0, [%i0]	! Store it back into memory
	xor	%l1, %i2, %l1	! xor op to light bank with pattern 2
	st	%l1, [%i0 + 4]	! Store it back into memory

	ret			! Return from subroutine
	restore			! Restore caller's window; in "ret" delay slot
