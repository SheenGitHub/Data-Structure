work : BinQueueCase.o BinQueue.o
	cc -o work BinQueueCase.o BinQueue.o
BinQueueCase.o : BinQueueCase.c BinQueue.h
	cc -D ElementType=int -c BinQueueCase.c
BinQueue.o : BinQueue.c BinQueue.h
	cc -D ElementType=int -D MaxTrees=8 -D Capacity=200 -c BinQueue.c
clean:
	rm *.o work
