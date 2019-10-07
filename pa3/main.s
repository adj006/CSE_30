/*
 * Filename: main.s
 * Author: Adrian Jimenez
 * Userid: cs30xib
 * Description: This is the main driver for the program.
 * Date: Nov. 8, 2013
 * Sources of Help: Discussion and tutors.
 */

	.global		main		! Declare the symbol to be globally
					! visible so we can call this function
					! from other modules.

PTRSIZ = 4
INTSIZ = 4

	.section	".data"		! the data segment begins here
usage:					! The format string to printf()
	.asciz	"Usage: %s [--build dictionary_file]\n"

fmt1:
	.asciz	"--build"

fmt2:
	.asciz	"/usr/dict/words"

	.section ".text"		! The text segment begins here

/*
 * Function name: main()
 * Function prototype: int main( int argc, char *argv[] );
 * Description: where the magic happens.
 * Parameters:
 *	arg 1: int argc -- the number of stdin arguments
 *	arg 2: char *argv[] -- a char array pointer to store in the stdin args
 * Side Effects: 
 * Error Conditions:
 * Return Value: 0 if successful
 * Registers Used:
 *	%i0 - arg 1
 *	%i1 - arg 2
 *
 *	%o0 - for "--build", for "/usr/dict/words"
 *	%o1 - for argv[1], for argv[2]
 *	%o2 -
 *	%o3 - 
 *
 *	%l0 - 
 *	%l1 - 
 *	%l2 - 
 *	%l3 - 
 *            
 *	%l3 -
 *	%l4 -
 */

main:
	! Save caller's window: if different than -( 92 + PTRSIZ + INTSIZ ) & -8
	! then comment on how that value was calculated.
	save	%sp, -( 92 + PTRSIZ + INTSIZ ) & -8, %sp

	cmp	%i0, 3	! compares argc with 3
	be	if1	! if equal then branch to first if
	nop

	cmp	%i0, 1	! compares argc with 1
	be	if1	! if equal then branch to first if
	nop

	ba	else2	! if not equals branch to last else
	nop

if1:
	
	cmp	%i0, 1	! compares argc with 1
	be	if2	! branch to 2nd if
	nop
	
	set	fmt1, %o0	! %o0 = "--build"
	ld	[%i1 + 4], %o1	! points to the address of this pointer
	!ld	[%o2], %o2	! now has the value
	call	strcmp		! calls the strcmp method to compare
	nop

	cmp	%o0, %g0	! compares the returned value with 0
	be	elseif		! if equals go to elseif
	nop

	ba	else1		! branch to else1
	nop

if2:

	sub	%fp, 8, %o0	! adress of angramInfo struct
	call	processDB	! call on processDB
	nop

	sub	%fp, 8, %o0	! adress of angramInfo struct
	call	userInteractive ! call on userInteractive
	nop

	ba	end		! branch to end
	nop

elseif:

	set	fmt2, %o0	! %o0 = "/usr/dict/words"
	ld	[%i1 + 8], %o1	! %o1 = argv[2]
	call	strcmp		! calls the strcmp method to compare
	nop

	cmp	%o0, %g0	! compares the result with 0
	bne	else1		! if not equal the branch to first else
	nop

	ld	[%i1 + 8], %o0	! %o0 = argv[2]
	call	buildDB		! calls the buildDB method
	nop

	ba	end		! branch to end
	nop

else1:

	mov	stdError, %o0	! set %o0 to stderr
	set	usage, %o1	! %o1 is not the usage message
	ld	[%i1], %o2	! %o2 = argv[0]
	call	fprintf		! calls the fprintf() method
	nop

	ba	end		! branch to end
	nop

else2:

	mov	stdError, %o0	! set %o0 to stderr
	set	usage, %o1	! %o1 is not the usage message
	ld	[%i1], %o2	! %o2 = argv[0]
	call	fprintf		! calls the fprintf() method
	nop
	
end:

	sub	%fp, 8, %o0
	call	free
	nop

	mov	%g0, %i0	! return value is 0

	ret		! Return from subroutine
	restore		! Restore caller's window; in "ret" delay slot
