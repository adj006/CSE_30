/*
 * Filename: printChar.s
 * Author: Adrian Jimenez
 * Userid: cs30xib
 * Description: This is the printChar() function for the display diamond
 * Date: Oct. 13, 2013
 * Sources of Help: printHello.s and discussion
 */

	.global printChar	! Declare the symbol to be globally visible so
				! we can call this function from other modules.

	.section ".data"	! The data segment begins here

fmt:				! The format string to printf()
	.asciz	"%c"

	.section ".text"	! The text segment begins here

/*
 * Function name: printChar()
 * Function prototype: void printChar( char ch );
 * Description: Prints to stdout a specified character.
 * Parameters: 
 *	arg 1: char ch -- the character to print
 * Side Effects: Outputs character with it supplied as argument.
 * Error Conditions: NONE
 * Return Value: None
 * Registers Used:
 *	%i0 - arg 1 -- the character (char) passed in to this function
 *	%o0 - param 1 
 *	%o1 - param 2
 */

printChar:
	save	%sp, -96, %sp	! Save caller's window; if different than -96
				! then comment on how that value was calculated.

	set	fmt, %o0	! Parameter 1 to printf() goes in register %o0
	mov	%i0, %o1	! Parameter 2 to printf() goes in register %o1
	call	printf, 2	! Make function call specifying # of params
	nop			! Delay slot for call instruction

	ret			! Return from subroutine
	restore			! Restore caller's window; in "ret" delay slot
