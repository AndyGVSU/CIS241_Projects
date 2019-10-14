p2: p2.o subcipher.o subcipher.h
	gcc -o p2 p2.o subcipher.o
p2.o: p2.c
	gcc -c p2.c
subcipher.o: subcipher.c subcipher.h
	gcc -c subcipher.c
test: test1 test2
	diff -s plain.txt rdata.txt
test1:
	./p2 e "GOODMORNING" plain.txt cipher.txt
test2:
	./p2 d "GOODMORNING" cipher.txt rdata.txt

clean:
	rm -f p2.o subcipher.o p2 cipher.txt rdata.txt
