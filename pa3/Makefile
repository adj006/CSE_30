#
# Makefile template for CSE 30 -- PA3
#

HEADERS		= anagrams.h

C_SRCS		= anagramCompare.c buildDB.c processDB.c\
		  sortedMemberCompare.c userInteractive.c globals.c

ASM_SRCS	= main.s charCompare.s

C_OBJS		= anagramCompare.o buildDB.o processDB.o\
		  sortedMemberCompare.o userInteractive.o globals.o

ASM_OBJS	= main.o charCompare.o

OBJS            = ${C_OBJS} ${ASM_OBJS}

EXE		= anagrams

#
# You should not need to change anything below this line
#

#
# Relevant man pages:
#
# man gcc
# man as
# man lint
#

GCC		= gcc
ASM		= $(GCC)
LINT		= lint

GCC_FLAGS	= -c -g -Wall -D__EXTENSIONS__ -std=c99
LINT_FLAGS1	= -c -err=warn
LINT_FLAGS2	= -u -err=warn
ASM_FLAGS	= -c -g
LD_FLAGS	= -g -Wall

#
# Standard rules
#

.s.o:
	@echo "Assembling each assembly source file separately ..."
	$(ASM) $(ASM_FLAGS) $<
	@echo ""

.c.o:
	@echo "Linting each C source file separately ..."
	$(LINT) $(LINT_FLAGS1) $<
	@echo ""
	@echo "Compiling each C source file separately ..."
	$(GCC) $(GCC_FLAGS) $<
	@echo ""

#
# Simply have our project target be a single default "a.out" executable.
#

$(EXE):	$(OBJS)
	@echo "2nd phase lint on all C source files ..."
	$(LINT) $(LINT_FLAGS2) *.ln
	@echo ""
	@echo "Linking all object modules ..."
	$(GCC) -o $(EXE) $(LD_FLAGS) $(OBJS)
	@echo "Done."

${C_OBJS}:      ${HEADERS}

clean:
	@echo "Cleaning up project directory ..."
	/usr/bin/rm -f *.o $(EXE) anagram.dat *.ln core
	@echo ""
	@echo "Clean."

new:
	make clean
	make

testcharCompare: test.h anagrams.h charCompare.s testcharCompare.c
	@echo "Compiling testcharCompare.c"
	gcc -g -o testcharCompare testcharCompare.c charCompare.s
	@echo "Done."

runtestcharCompare: testcharCompare
	@echo "Running testcharCompare"
	@./testcharCompare

testanagramCompare: test.h anagrams.h anagramCompare.c testanagramCompare.c
	@echo "Compiling testanagramCompare.c"
	gcc -g -o testanagramCompare testanagramCompare.c anagramCompare.c
	@echo "Done."

runtestanagramCompare: testanagramCompare
	@echo "Running testanagramCompare"
	@./testanagramCompare

testsortedMemberCompare: test.h anagrams.h sortedMemberCompare.c testsortedMemberCompare.c
	@echo "Compiling testsortedMemberCompare.c"
	gcc -g -o testsortedMemberCompare testsortedMemberCompare.c sortedMemberCompare.c
	@echo "Done."

runtestsortedMemberCompare: testsortedMemberCompare
	@echo "Running testsortedMemberCompare"
	@./testsortedMemberCompare
