CC = gcc
CFLAGS = -Wall -Wextra -Werror -Wshadow -Wsign-conversion
CSRC = $(wildcard c/*.c)
CEXEC = $(patsubst %.c,%.cout,$(CSRC))

CXX = g++
CXXFLAGS = -pedantic -std=c++17
CXXSRC = $(wildcard cpp/*.cpp)
CXXEXEC = $(patsubst %.cpp,%.cppout,$(CXXSRC))

.PHONY: all
all: $(CEXEC) $(CXXEXEC)

%.cout: %.c
	$(CC) $(CFLAGS) -o $@ $<

%.cppout: %.cpp
	$(CXX) $(CFLAGS) $(CXXFLAGS) -o $@ $<

.PHONY: run
.SILENT: run
run: $(CEXEC) $(CXXEXEC)
	for out in c/*.cout; do echo "\nTask $$out:"; $$out; done
	for out in cpp/*.cppout; do echo "\nTask $$out:"; $$out; done

.PHONY: clean
.SILENT: clean
clean:
	rm -f $(CEXEC) $(CXXEXEC)