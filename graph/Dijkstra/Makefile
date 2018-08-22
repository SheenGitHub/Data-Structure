work : DijkstraCase.o Dijkstra.o
	cc -o work DijkstraCase.o Dijkstra.o
DijkstraCase.o : DijkstraCase.c Dijkstra.h AdjTable.h
	cc -D NumVertex=7 -c DijkstraCase.c
Dijkstra.o : Dijkstra.c Dijkstra.h AdjTable.h
	cc -D NumVertex=7 -c Dijkstra.c
clean:
	rm *.o work
