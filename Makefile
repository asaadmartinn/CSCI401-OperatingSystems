# list/Makefile
#
# Makefile for list implementation and test file.
#
# <Asaad Martin>
list: list.c main.c
	gcc -o list list.c main.c -I.