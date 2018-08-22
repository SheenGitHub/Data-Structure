
work : SortCase.o Sort.o
	cc -o work SortCase.o Sort.o
SortCase.o : SortCase.c Sort.h
	cc -D ElementType=int -c SortCase.c
Sort.o : Sort.c Sort.h
	cc -D ElementType=int -c Sort.c
clean:
	rm *.o work
