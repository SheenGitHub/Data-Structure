work : BinHeapCase.o BinHeap.o
	cc -o work BinHeapCase.o BinHeap.o
BinHeapCase.o : BinHeapCase.c BinHeap.h
	cc -D ElementType=int -c BinHeapCase.c
BinHeap.o : BinHeap.c BinHeap.h
	cc -D ElementType=int -D MinPQSize=10 -c BinHeap.c
clean:
	rm *.o work
