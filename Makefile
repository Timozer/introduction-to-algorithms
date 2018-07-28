DEPDIR=depends

# "Machine-dependant" options
#MFLAGS=-fPIC

CFLAGS=-c -g -O3 -fPIC -Wall -Werror -Wsign-compare -Isrc -Ilib
LDFLAGS=-g -O3 -Wall -Werror 
CC=gcc
CPP=g++

MAIN_SRC=\
		 src/main.o \
		 lib/log.o \
		 lib/time_analyzer.o \
		 lib/sort.o
		 

all:		main

.PHONY:		all clean

# libraries

libsundown.so.1: $(SUNDOWN_SRC)
	$(CC) $(LDFLAGS) -shared -Wl $^ -o $@

# executables

sundown:	examples/sundown.o $(SUNDOWN_SRC)
	$(CC) $(LDFLAGS) $^ -o $@

main: $(MAIN_SRC)
	$(CPP) $(LDFLAGS) $^ -o $@


# housekeeping
clean:
	rm -f *~ src/*~ lib/*~
	rm -f src/*.o lib/*.o

# generic object compilations

%.o:	src/%.cpp lib/%.cpp
	#@mkdir -p $(DEPDIR)
	#@$(CC) -MM $< > $(DEPDIR)/$*.d
	$(CPP) $(CFLAGS) -o $@ $<

