CC=gcc
CFLAGS=-Wall
RM=rm -f

all: testPattern

testPattern: testPattern.c
	$(CC) $(CFLAGS) testPattern.c -o testPattern
    
clean:
	$(RM) testPattern *~
