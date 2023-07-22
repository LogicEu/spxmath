# spxmath Makefile

SRC=test.c
EXE=spxmtest
HEADER=spxmath.h
SCRIPT=build.sh

CC=gcc
STD=-std=c89
OPT=-O2
WFLAGS=-Wall -Wextra -pedantic
INC=-I.
LIB=-lm

CFLAGS=$(STD) $(OPT) $(WFLAGS) $(INC) $(LIB)

$(EXE): $(SRC) $(HEADER)
	$(CC) $< -o $@ $(CFLAGS)

clean:
	$(RM) $(EXE)

install: $(SCRIPT)
	./$< $@

uninstall: $(SCRIPT)
	./$< $@
