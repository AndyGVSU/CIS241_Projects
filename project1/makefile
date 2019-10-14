proj1: proj1.o sort.h sort.o
	gcc -o proj1 proj1.o sort.o

proj1.o: sort.h sort.c proj1.c
	gcc -c proj1.c

sort.o: sort.h sort.c
	gcc -c sort.c

run:	proj1
	./proj1

clean:
	rm -f proj1.o sort.o proj1


