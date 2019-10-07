/*
 * Filename: strToULong.s
 * Author: Adrian Jimenez
 * Userid: cs30xib
 * Description: This function converts the input strings to long integers.
 * Date: Oct. 27, 2013
 * Sources of Help:
 */

	.global		strToULong	! Declare the symbol to be globally
					! visible so we can call this function
					! from other modules.
					
BUFSIZ = 1024
PTRSIZ = 4
ptrOffset = 4
bufOffset = 1028
!NL = '\n'

	.section	".data"		! The data segment begins here

fmt1:					! The format string to printf()

	.asciz	"\n\tConverting \"%s\" base \"%d\""

fmt2:					! The format string to printf()

	.asciz	"\n\t\"%s\" is not an integer\n\n"

fmt3:
	.asciz	"\n"

	.section	".text"		! The text segment begins here

/*
 * Function name: strToULong()
 * Function prototype: unsigned long strToULong( const char* str,
 *                                               const int base );
 * Description: converts a string to a long.
 * Parameters:
 	arg 1: const char* str -- the string that needs to be converted
	arg 2: const int base -- the base of the long we want to convert to
 * Side Effects: converts to a long.
 * Error Conditions:
 * Return Value: unsigned long
 * Registers Used:
 *	%i0 - arg 1
 *	%i1 - arg 2
 *	%i2 - arg 3
 *
 *	%o0 - 1st arg for call on printf and snprintf
 *	%o1 - 2nd arg for call on printf and snprintf
 *	%o2 - 3rd arg for call on printf and snprintf
 *	%o3 - 4th arg for call on snprintf
 *	%o4 - 5th arg for call on snprintf
 *
 *	%l0 - address of endptr
 *	%l1 - value of errno
 *	%l2 - temp value for errno
 */

strToULong:

	! Save caller's window; if different than -( 92 + PTRSIZ + BUFSIZ ) & -8
	! then comment on how that value was calculated.
	save	%sp, -( 92 + PTRSIZ + BUFSIZ ) & -8, %sp

	sub	%fp, ptrOffset, %l0	! %l0 is now the address of endptr

	set	errno, %l1	! sets errno to %l1
!	ld	[%l1], %l1	! %l1 now holds the value of errno
!	clr	%l2		! sets errno to 0
	st	%g0, [%l1]	! store it back into memory

	mov	%i0, %o0	! copy 1st arg into %o0
	mov	%l0, %o1	! copy endptr to %o1
	mov	%i1, %o2	! copy 2nd arg into %o2
	call	strtoul, 3	! calls strtoul() on 3 args
	nop
	
	set	errno, %l1	! sets errno to %l1
	ld	[%l1], %l1	! %l1 now holds the value of errno
	
	cmp	%l1, %g0	! compares errno with 0
	bne	if1		! if errno = 0 jump to if1
	nop

	ld	[%fp - ptrOffset], %l0		! %l0 now holds the address
						! that ptr is referencing
	ldub	[%l0], %l0		! %l0 now holds the value of the
					! char that ptr is referencing

	cmp	%g0, %l0	! compares 0 with the value of ptr
	be	ptr_OK		! The character that ptr is referencing is '\0'
				! so jump to that portion of code
	nop

	cmp	%g0, %l0	! compares 0 with the value of ptr
	bne	if2		! if endptr != '\0' jump to if2
	nop

if1:

	sub	%fp, bufOffset, %o0	! the address of buf is now in %o0
	mov	BUFSIZ, %o1	! the value of BUFSIZ is now in %o1
	set	fmt1, %o2	! the string is now in %o2
	mov	%i0, %o3	! copies char pointer to %o3
	mov	%i1, %o4	! copies base to %o4
	call	snprintf, 5	! calls snprintf() on 5 args
	nop

	sub	%fp, bufOffset, %o0

	call	perror, 1	! calls perror() on 1 arg
	nop

	set	fmt3, %o0		! %o0 = '\n'
	call	printf, 1	! calls printChar()
	nop

	mov	-1, %i0		! return -1
	ba	end		! branch to end
	nop

if2:

	set	stdError, %o0	! sets stdError into %o0
	ld	[%o0], %o0	! now %o0 holds the value of stderr
	set	fmt2, %o1	! copies string into %o1
	mov	%i0, %o2	! copies 1st arg into %o2
	call	fprintf, 3	! calls fprintf() with 3 args
	nop

	set	errno, %l1	! sets errno to %l1

	mov	-1, %l2		! errno = -1
	st	%l2, [%l1] 
	mov	%l2, %i0		! return -1

	ba	end		! branch to the end
	nop

ptr_OK:

	mov	%o0, %i0	! store the result back into return value

end:

	ret			! Return from subroutine
	restore			! Restore caller's window; in "ret" delay slot
