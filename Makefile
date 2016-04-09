all:
	cc -Wall -o kmp kmp.c debug.c main.c 

astyle:
	astyle -s2 *.c *.h
