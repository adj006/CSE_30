/*
 * Filename: ripple.s
 * Author: Adrian Jimenez
 * Userid: cs30xib
 * Description: This function rotates the current light patterns in the light
 *              banks by rippleCnt places displaying the light banks after
 *              each single bit rotate.
 * Date: Oct. 27, 2013
 * Sources of Help:
 */

 	.global		ripple		! Declare the symbol to be globally
					! visible so we can call this function
					! from other modules.

	.section	".data"		! The data segment begins here

	.section	".text"		! The text segment begins here

/*
 * Function Name: ripple()
 * Function Prototype: void ripple( unsigned int lightBank[],
 *                                  const int rippleCnt );
 * Description: Causes a ripple effect.
 * Parameters:
 *	arg 1: unsigned int lightBank[] -- the array of light banks
 *	arg 1: const int rippleCnt -- the places the lights will rotate
 * Side Effects: Ripple effect
 * Error Conditions:
 * Return Value: None
 * Registers Used:
 *	%i0 - arg 1
 *	%i1 - arg 2
 *
 *	%l0 - ripple counter
 *	%l1 - address of lightBank[1]
 *	%l2 - address of rippleCnt
 */

ripple:

	save	%sp, -96, %sp	! Save caller's window; if different than -96
				! then comment on how that value was calculated.

	cmp	%g0, %i1	! compares 0 with rippleCnt
	be	end		! if equals do nothing
	nop
	
	mov	0, %l0		! rippleCnt counter

	cmp	%i1, %g0	! compares 0 with rippleCnt
	bl	else		! If rippleCnt negative jump to else
	nop

	mov	1, %l1		! sets rotateCnt to 1

	ba	loop		! jumps to loop label
	nop

else:

	mov	-1, %l1		! sets rotateCnt to -1
	neg	%i1		! negates rippleCnt

loop:

	mov	%i0, %o0	! copies light bank to %o0
	mov	%l1, %o1	! copies rotateCnt to %o1
	call	rotate, 2	! calls the rotate function passing 2 args
	nop

	call	displayLights, 1	! calls displayLights function passing
					! 1 argument

	inc	%l0		! %l0++
	cmp	%l0, %i1	! compares rippleCnt counter with absolute
				! value of rippleCnt
	bl	loop		! if it's less than jump back to loop
	nop

end:

	ret			! Return from subroutine
	restore			! Restore caller's window; in "ret" delay slot
