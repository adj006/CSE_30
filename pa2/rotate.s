/*
 * Filename: rotate.s
 * Author: Adrian Jimenez
 * Userid: cs30xib
 * Description: This function rotates the current light patterns in the light
 *              banks by rotateCnt places.
 * Date: Oct. 27, 2013
 * Sources of Help:
 */

 	.global		rotate		! Declare the symbol to be globally
					! visible so we can call this function
					! from other modules.

	.section	".data"		! The data segment begins here

MSB_MASK = 0x80000000
LSB_MASK = 0x00000001
SIXBIT_MASK = 0x0000003F

	.section	".text"		! The text segment begins here

/*
 * Function Name: rotate()
 * Function Prototype: void rotate( unsigned int lightBank[],
 *                                  const int rotateCnt );
 * Description: Rotates the pattern of the lights.
 * Parameters:
 *	arg 1: unsigned int lightBank[] -- the array of light banks
 *	arg 2: const int rotateCnt -- the places the lights will rotate
 * Side Effects:
 * Error Conditions:
 * Return Value: None
 * Registers Used:
 *	%i0 - arg 1
 *	%i0 - arg 2
 *
 *	%l0 - address of lightBank[0]
 *	%l1 - address of lightBank[1]
 *	%l2 - address of rotateCnt
 *	%l3 - value of SIXBIT_MASK
 *	%l4 - value of MSB of lightBank[1] and LSB of lightBank[0]
 *	%l5 - loop counter
 *	%l6 - MSB
 *	%l7 - value of LSB of lightBank[1] and MSB of lightBank[0]
 */

rotate:

	save	%sp, -96, %sp	! Save caller's window; if different than -96
				! then comment on how that value was calculate.

	ld	[%i0], %l0	! %l0 = lightBank[0]
	ld	[%i0 + 4], %l1	! %l1 = lightBank[1]

	cmp	%g0, %i1	! Compares 0 with the rotateCnt
	be	end		! If rotateCnt = 0 do nothing
	nop

	set	MSB_MASK, %l2	! The value in %l2 is the mask we will use
				! to get the sign
	and	%l2, %i1, %l2	! The value in %l2 is now just the sign bit

	set	SIXBIT_MASK, %l3	! The value in %l3 is the mask we will
					! use on the count
	and	%l3, %i1, %l3	! The value in %l3 is now the lower six bits
				! of rotate count

	cmp	%g0, %l2	! Compare the sign bit with zero
	bne	rotate_right	! Sign bit was set, jump to rotate_right
	nop

	set	MSB_MASK, %l6	! The value in %l6 is the mask we will use
				! to get the sign

	mov	0, %l5		! loop counter %l5

loop1:

	and     %l0, %l6, %l4   ! %l4 now holds the LSB of
				! lightBank[0], pre-shift
	and	%l1, %l6, %l7	! %l7 now holds the LSB of
				! lightBank[1], pre-shift
	srl     %l4, 31, %l4    ! %l4 now holds the MSB of lightBank[0],
				! pre-shift, in its LSB
	srl     %l7, 31, %l7    ! %l7 now holds the MSB of lightBank[1],
				! pre-shift, in its LSB
	sll     %l0, 1, %l0     ! %l0 now holds the shifted value of
				! lightBank[0]
	sll     %l1, 1, %l1     ! %l1 now holds the shifted value of
				! lightBank[1]
	or      %l4, %l1, %l1   ! %l1 now has a correct LSB based on
				! lightBank[0]'s MSB
	or      %l7, %l0, %l0   ! %l0 now has a correct LSB based on
				! lightBank[1]'s MSB
	
	inc     %l5             ! %l5++
	cmp     %l5, %i1        ! compare the loop counter with shift counter
	bl      loop1           ! if loop counter less than shift counter
	nop

	cmp     %g0, %l2
	be      end
	nop     

rotate_right:

	neg     %i1
	set     SIXBIT_MASK, %l3        ! The value in %l3 is the mask we will
					! use on the count
	and     %l3, %i1, %l3   ! The value in %l3 is now the lower six bits
				! of shift count
	
	mov     0, %l5          ! loop counter %l5
	
loop2:

	and     %l0, LSB_MASK, %l4      ! %l4 now holds the LSB of
					! lightBank[0], pre-shift
	and     %l1, LSB_MASK, %l7      ! %l7 now holds the LSB of
					! lightBank[1], pre-shift
	sll     %l4, 31, %l4    ! %l4 now holds the LSB of lightBank[0],
				! pre-shift, in its MSB
	sll     %l7, 31, %l7    ! %l7 now holds the LSB of lightBank[1],
				! pre-shift, in its MSB
	srl     %l0, 1, %l0     ! %l0 now holds the shifted value of
				! lightBank[0]
	srl     %l1, 1, %l1     ! %l1 now holds the shifted value of
				! lightBank[1]
	or      %l4, %l1, %l1   ! %l1 now has a correct MSB based on
				! lightBank[0]'s LSB
	or      %l7, %l0, %l0   ! %l0 now has a correct MSB based on
				! lightBank[1]'s LSB
	
	inc     %l5             ! %l5++
	cmp     %l5, %i1        ! compare the loop counter with shift counter
	bl      loop2           ! if loop counter less than shift counter
	nop


end:

	st	%l0, [%i0]	! Store lightBank[0] back into memory
	st	%l1, [%i0 + 4]	! Store lightBank[1] back into memory

	ret			! Return from subroutine
	restore			! Restore caller's window; in "ret" delay slot
