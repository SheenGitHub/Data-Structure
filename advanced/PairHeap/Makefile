work : PairHeapCase.o PairHeap.o
	cc -o work PairHeapCase.o PairHeap.o
PairHeapCase.o : PairHeapCase.c PairHeap.h
	cc -c PairHeapCase.c
PairHeap.o : PairHeap.c PairHeap.h
	cc -c PairHeap.c
clean:
	rm *.o work
