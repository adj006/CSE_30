/*
 * Filename: displayLights.s
 * Author: Adrian Jimenez
 * Userid: cs30xib
 * Description: This function displays the light banks.
 * Date: Oct. 26, 2013
 * Sources of Help:
 */

	.global		displayLights	! Declare the symbol to be globally
					! visible so we can call this function
					! from other modules.
	.section	".data"		! the data segment begins here

STAR = '*'
HYPHEN = '-'
SPACE = ' '
NL = '\n'

fmt:					! The format string to printf()
	.asciz	"%c"

	.section ".text"		! The text segment begins here

/*
 * Function name: displayLights()
 * Function prototype: void displayLights( const unsigned int lightBank[] );
 * Description: Prints to stdout the specified characters to display lights
 * Parameters:
 *	arg 1: const unsigned int lightBank[] -- the array of light banks
 * Side Effects: Outputs characters with it supplied as argument.
 * Error Conditions:
 * Return Value: None
 * Registers Used:
 *	%i0 - arg 1 -- the integer array passed in to this function
 *
 *	%o0 - param 1 to printf() -- format string
 *	%o1 - param 2 to printf() -- copy of arg 1 being passed in
 *
 *	%l0 - lightBank[0] & lightBank[1]
 *	%l1 - 0x80000000, the hexadecimal used to compare
 *	%l2 - the index variable for keeping track of how many bits have been
 *            compared
 *	%l3 - local variable to keep track of how many light banks completed
 *	%l4 - local variable used to store the result after the and operation
 */

displayLights:

	save	%sp, -96, %sp	! Save caller's window; if different than -96
				! then comment on how that value was
				! calculated.

	ld	[%i0], %l0	! %l0 = lightBank[0]
	set 	0x80000000, %l1	! %l1 = 0x80000000
	mov	0, %l2		! int i = 0
	mov	0, %l3		! %l3 = 0

loop:

	and	%l0, %l1, %l4	! And op to input and %l1 and store in %l4
	cmp	%l4, %l1	! compares the result to %l1
	bne	else		! if it's not equal branch to else
	nop

	mov	STAR, %o0	! %o0 = '*'
	call	printChar, 1		! prints out 1 character
	nop
inc_i:
	inc	%l2		! i++

	mov	%l2, %o0	! copy index to %o0
	mov	4, %o1		! %o1 = 4
	call	.rem		! i % 4
	nop

	cmp	%o0, 0		! i % 4 == 0
	be	space		! if it's equal print the space
	nop

	srl	%l1, 1, %l1	! shift %l1 to the right by 1
	cmp	%l1, 0		! compares %l1 with 0
	bne	loop		! if it's not equal go to loop
	nop

	ba	next
	nop

else:

	mov	HYPHEN, %o0	! %o0 = '-'
	call	printChar, 1		! prints out 1 character
	nop

	ba	inc_i		! if it's not equal go to loop
	nop


space:

	mov	SPACE, %o0	! %o0 = ' '
	call	printChar, 1		! prints out 1 character
	nop

	srl	%l1, 1, %l1	! shift %l1 to the right by 1
	cmp	%l1, 0		! compares %l1 with 0
	bne	loop		! if it's not equal go to loop
	nop

next:

	inc	%l3		! %l3++
	cmp	%l3, 2		! compares %l3 with 2
	be	end		! if it's equal go to end
	nop

	ld	[%i0 + 4], %l0	! %l0 = lightBank[1]
	set 	0x80000000, %l1	! %l1 = 0x80000000
	ba	loop		! branches back to the loop
	nop

end:

	mov	NL, %o0		! %o0 = '\n'
	call	printChar, 1		! prints out 1 character
	nop

	ret			! Return from subroutine
	restore			! Restore caller's window; in "ret" delay slot
