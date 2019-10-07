#
# Makefile for CSE 30 -- PAMT2 
#

HEADERS		= pamt2.h

C_SRCS		= is_prime.cpp main.cpp 

C_OBJS		= is_prime.o main.o

OBJS		= ${C_OBJS}

EXE		= isPrime

#
# Relevant man pages:
#
# man -M /software/common/gnu/man g++
#

GCC		= g++

GCC_FLAGS	= -g -O3 -lpthread -c -Wall -std=c++11
LD_FLAGS	= -g -lpthread -Wall

#
# Standard rules
#

.cpp.o:
	@echo "Compiling each C source file separately ..."
	$(GCC) $(GCC_FLAGS) $<
	@echo ""

#
# Simply have our project target be a single default $(EXE) executable.
#

$(EXE):	$(OBJS)
	@echo "Linking all object modules ..."
	$(GCC) -o $(EXE) $(LD_FLAGS) $(OBJS)
	@echo ""
	@echo "Done."

${C_OBJS}:      ${HEADERS}

clean:
	@echo "Cleaning up project directory ..."
	rm -f *.o $(EXE) *.ln core a.out
	@echo ""
	@echo "Clean."

new:
	make clean
	make

