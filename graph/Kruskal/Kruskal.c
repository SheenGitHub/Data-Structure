#include <stdio.h>
#include "BinHeap.h"
#include "DisjSet.h"
#include "Graph.h"

void 
Kruskal( Graph G, int NumVertex, int NumEdges )
{
	int EdgesAccepted;
	DisjSet S;
	PriorityQueue H;
	Vertex U, V;
	SetType USet, VSet;
	Edge E;

	InitializeDisjSet( S );
	H = InitializeHeap( NumEdges );
	ReadGraphIntoHeapArray( G, H , NumEdges);
	BuildHeap( H );

	EdgesAccepted = 0;
	while( EdgesAccepted < NumVertex - 1 )
	{
		E = DeleteMin( H );

		VSet = Find( E.V, S );
		USet = Find( E.U, S );
		if( USet != VSet )
		{
			printf("Add Vertex %d and %d \n", E.V, E.U );
			EdgesAccepted++;
			SetUnion( S, USet, VSet );
		}
	}
}

int 
main(){
	Graph 
	Input = 
	{
		{ 1, 2, 2 },
		{ 1, 3, 4 },
		{ 1, 4, 1 },
		{ 2, 4, 3 },
		{ 2, 5, 10 },
		{ 3, 4, 2 },
		{ 3, 6, 5 },
		{ 4, 5, 7 },
		{ 4, 6, 8 },
		{ 4, 7, 4 },
		{ 5, 7, 6 },
		{ 6, 7, 1 }
	};
	Kruskal( Input, 7, 12 );

}
