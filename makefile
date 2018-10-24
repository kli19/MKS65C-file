all: file.o
	gcc file.o

file.o: file.c 
	gcc -c file.c

clean:
	rm *.o
	rm a.out
	rm *.txt

run:
	./a.out
