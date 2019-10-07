/*
 * Filename: displayDiamond.s
 * Author: Adrian Jimenez
 * Userid: cs30xib
 * Description: This file is to display a diamond
 * Date: Oct. 11, 2013
 * Sources of Help: tutors
 */

	.global		displayDiamond		! Declare the sysmol to be
						! globally visible so we can
						! call this function from other
						! modules.
	.section	".data"			! The data segment begins here
NL = '\n'
	.section	".text"			! The test segment begins here
/*
 * Function name: displayDiamond()
 * Function prototype: void displayDiamond( lond width, long height,
 *                                          long borderCh, long diamondCh );
 * Description: Prints to stdout a specified diamond.
 * Parameters:
 *      arg 1: long width -- the width of the diamond
 *      arg 2: long height -- the height of the diamond
 *      arg 3: long borderCh -- the border character of the diamond
 *      arg 4: long diamondCh -- the diamond character of the diamond
 * Side Effects: Outputs diamond with it supplied as argument.
 * Error Conditions: checks if it's within range
 * Return Value: None
 * Registers Used:
 *      %i0 - arg 1 
 *      %i1 - arg 2
 *      %i2 - arg 3
 *      %i3 - arg 4
 *	Too many. =[
 */


displayDiamond:

	save	%sp, -96, %sp	! Save caller's window; if different than -96
                                ! then comment on how that value was calculated.


	mov	1, %l0		! %l0 = col
	cmp	%l0, %i0	! comparing col and width
	bg	top_border_end_loop	! if col <= width go through loop
	nop

top_border_loop:
	mov	%i2, %o0	! %o0 = borderCh
	call	printChar, 1	! prints the borderCh
	nop
	inc	%l0		! col++
	cmp	%l0, %i0	! comparing col and width
	ble	top_border_loop	! if col <= width go through loop again
	nop

top_border_end_loop:
	mov	NL, %o0		! %o0 = '\n'
	call	printChar, 1	! prints the new line character
	nop


	mov	1, %l0		! %l0 = row
	sub	%i1, 2, %l1	! %l1 = height - 2
	cmp	%l0, %l1	! comparing row and height
	bg	top_half_end_out_loop	! if row <= height go through loop
	nop

top_half_out_loop:
	sub	%i0, %l0, %o0	! %o0 = width - row
	mov	2, %o1		! %o1 = 2
	call	.div		! divides %o0/%o1
	nop

	mov	%o0, %l3	! %l3 = outer = (width - row)/2
	cmp	%l3, 1		! compares outer with 1
	bl	top_half_end_in_loop_1	! if it is less than goto branch
	nop

top_half_in_loop_1:
	mov	%i2, %o0	! %o0 = borderCh
	call	printChar, 1	! prints 1 character
	nop

	dec	%l3		! decriments outer
	cmp	%l3, 1		! compares outer with 1
	bge	top_half_in_loop_1	! if greater than or equal take branch
	nop

top_half_end_in_loop_1:

	mov	1, %l2 		! %l2 = inner
	cmp	%l2, %l0	! compares row with inner
	bg	top_half_end_in_loop_2	! if greater than take the branch
	nop

top_half_in_loop_2:
	mov	%i3, %o0	! %o0 = diamondCh
	call	printChar, 1	! prints 1 character
	nop

	inc	%l2		! increments inner
	cmp	%l2, %l0	! compares inner with row
	ble	top_half_in_loop_2	! if less than or equal take branch
	nop

top_half_end_in_loop_2:

	sub	%i0, %l0, %o0	! %o0 = width - row
	mov	2, %o1		! %o1 = 2
	call	.div		! divides %o0/%o1
	nop
	mov	%o0, %l4	! %l4 = outer = (width - row)/2
	cmp	%l4, 1		! compares outer with 1 
	bl	top_half_end_in_loop_2	! if less than take branch
	nop

top_half_in_loop_3:
	mov	%i2, %o0	! %o0 = borderCh
	call	printChar, 1	! prints 1 character
	nop
	dec	%l4		! decriments outer
	cmp	%l4, 1		! compares outer with 1
	bge	top_half_in_loop_3	! if greater than or equal take branch
	nop

top_half_end_in_loop_3:

	mov	NL, %o0		! %o0 = '\n'
	call	printChar,1	! prints 1 character
	nop

	add	%l0, 2, %l0	! row += 2
	cmp	%l0, %l1	! compares row with height - 2
	ble	top_half_out_loop	! if less than or equal take branch
	nop

top_half_end_out_loop:

	mov	%i1, %l0	! row = height
	cmp	%l0, 0		! compares height with 0
	bl	bottom_half_end_out_loop
	nop

bottom_half_out_loop:

	sub	%i0, %l0, %o0	! %o0 = width - row
	mov	2, %o1		! %o1 = 2
	call	.div		! divides %o0/%o1
	nop

	mov	%o0, %l1	! %l1 = outer
	cmp	%l1, 1		! compares outer with 1
	bl	bottom_half_end_in_loop_1	! if less than then take branch
	nop

bottom_half_in_loop_1:

	mov	%i2, %o0	! %o0 = borderCh
	call	printChar, 1
	nop

	dec	%l1
	cmp	%l1, 1		! compares outer with 1	
	bge	bottom_half_in_loop_1
	nop

bottom_half_end_in_loop_1:

	mov	1, %l2		! inner = 1
	cmp	%l1, %l0	! compares inner with row
	bg	bottom_half_end_in_loop_2
	nop

bottom_half_in_loop_2:

	mov	%i3, %o0	! %o0 = diamondCh
	call	printChar, 1
	nop

	inc	%l2
	cmp	%l2, %l0
	ble	bottom_half_in_loop_2
	nop

bottom_half_end_in_loop_2:

	sub	%i0, %l0, %o0	! %o0 = width - row
	mov	2, %o1		! %01 = 2	
	call	.div
	nop

	mov	%o0, %l1	! store val into %l1
	cmp	%l1, 1
	bl	bottom_half_end_in_loop_3
	nop

bottom_half_in_loop_3:

	mov	%i2, %o0	! %o0 = borderCh
	call	printChar, 1
	nop

	dec	%l1
	cmp	%l1, 1
	bge	bottom_half_in_loop_3
	nop

bottom_half_end_in_loop_3:

	mov	NL, %o0
	call	printChar, 1
	nop

	sub	%l0, 2, %l0	! row -= 2
	cmp	%l0, 0
	bge	bottom_half_out_loop
	nop

bottom_half_end_out_loop:

	mov	1, %l0		! col = 1
	cmp	%l0, %i0	! compares col with width
	bg	bottom_border_end_loop
	nop

bottom_border_loop:

	mov	%i2, %o0	! %o0 = borderCh
	call	printChar, 1
	nop

	inc	%l0
	cmp	%l0, %i0	! compares col with width
	ble	bottom_border_loop
	nop

bottom_border_end_loop:

	mov	NL, %o0
	call	printChar, 1
	nop


	ret			! Return from subroutine
	restore			! Restore caller's window; in "ret" delay slot
