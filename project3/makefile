lab5: storelist.h storelist.o store.o
	gcc -o store storelist.o store.o

lab5.o: storelist.h store.c
	gcc -c store.c

list.o: storelist.h storelist.c
	gcc -c storelist.c

run:
	./store

clean:
	rm -f *.o store
