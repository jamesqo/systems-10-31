CFLAGS:=-Wall -Werror

all: main

main: main.o
	gcc -o main main.o

main.o: main.c
	gcc $(CFLAGS) -c main.c

clean:
	rm -f *.exe *.o main *~

run: all
	./main