work : LeftHeapCase.o LeftHeap.o
	cc -o work LeftHeapCase.o LeftHeap.o
LeftHeapCase.o : LeftHeapCase.c LeftHeap.h
	cc -D ElementType=int -c LeftHeapCase.c
LeftHeap.o : LeftHeap.c LeftHeap.h
	cc -D ElementType=int -c LeftHeap.c
clean:
	rm *.o work
