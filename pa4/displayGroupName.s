/*
 * Filename: displayGroupName.s
 * Author: Adrian Jimenez
 * Userid: cs30xib
 * Description: Displays the group name of the file
 * Date: Nov. 23, 2013
 * Sources of Help: Discussion and tutors.
 */

 	.global		displayGroupName! Declare the symbol to be globally
					! visible so we can call this function
					! from other modules.

PTRSIZ = 4

	.section ".data"		! The data segment begins here

fmt1:
	.asciz	"%-8s "

fmt2:
	.asciz	"%-8id "

	.section ".text"		! The text segment begins here

/*
 * Function name: displayGroupName()
 * Function prototype: void displayGroupName( const gid_t gid );
 * Description: displays the group
 * Parameters:
 *	arg 1: numerical ID for the group
 * Side Effects: 
 * Error Conditions:
 * Return Value: none
 * Registers Used:
 *	%i0 - arg 1 --
 *
 *	%o0 - the copy of the first arg
 *	%o1 - the copy of the return value of getgrgid
 *            
 */

displayGroupName:

	save	%sp, -(92 + PTRSIZ) & -8, %sp	! Save caller's window

	mov	%i0, %o0	! copies the argument into %o0
	call	getgrgid	! calls the getgrgid
	nop

	cmp	%o0, %g0 	! compares the return value with NULL
	be	else		! if it's not equal it will go to else

	ld	[%o0], %o1	! load the return value into %o1
	set	fmt1, %o0	! sets the string into %o0

	call	printf		! calls the printf function
	nop

	ba	end		! always branches to the end
	nop

else:

	set	fmt2, %o0	! sets the string into %o0
	mov	%i0, %o1	! copies the argument into %o1

	call	printf		! calls the printf function
	nop

end:

	ret		! Return from subroutine
	restore		! Restore caller's window
