work : Kruskal.o BinHeap.o DisjSet.o
	cc -o work Kruskal.o BinHeap.o DisjSet.o
Kruskal.o : Kruskal.c BinHeap.h DisjSet.h Graph.h
	cc -D NumSets=7 -c Kruskal.c
BinHeap.o : BinHeap.c Graph.h BinHeap.h
	cc -D ElementType=Edge -D MinPQSize=10 -c BinHeap.c
DisjSet.o : DisjSet.c DisjSet.h
	cc -D NumSets=7 -c DisjSet.c
clean:
	rm *.o work

