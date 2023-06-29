CC = gcc
C_SRCS = $(wildcard c/*.c)
C_PROGS = $(patsubst %.c,%.cout,$(C_SRCS))

CPPC = g++
CPP_SRCS = $(wildcard cpp/*.cpp)
CPP_PROGS = $(patsubst %.cpp,%.cppout,$(CPP_SRCS))

.PHONY: all
all: $(C_PROGS) $(CPP_PROGS)

%.cout: %.c
	$(CC) -Wall -Wextra -o $@ $<

%.cppout: %.cpp
	$(CPPC) -Wall -Wextra -pedantic -std=c++1y -o $@ $<

.PHONY: run
run: $(C_PROGS) $(CPP_PROGS)
	for out in c/*.cout; do echo "\nTask $$out:"; $$out; echo "\n"; done
	for out in cpp/*.cppout; do echo "\nTask $$out:"; $$out; echo "\n"; done

.PHONY: clean
clean:
	rm -f $(C_PROGS) $(CPP_PROGS)