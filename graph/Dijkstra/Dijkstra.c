#include <stdio.h>
#include <stdlib.h>
#include "Dijkstra.h"

struct AdjVNode
{
	Vertex        AdjV;
	WeightType    Weight;
	PtrToAdjVNode Next;
};

static void ReadGraph( Graph, Table );
static Vertex FindSmallestUnkownVertex( Table T );

void 
InitTable( Vertex start, Graph G, Table T )
{
	int i;
	ReadGraph( G, T );
	for( i = 0; i < NumVertex; i++ )
	{
		T[ i ].Known = False;
		T[ i ].Dist  = Infinity;
		T[ i ].Path  = NotAVertex;
	}
	T[ start ].Dist = 0;
}

static void 
ReadGraph( Graph G, Table T )
{
	int i, j;
	PtrToAdjVNode Node, PreNode;

	for( i = 0; i < NumVertex; i++ )
	{
		PreNode = malloc( sizeof( struct AdjVNode ) );
		if( PreNode == NULL )
			perror( "Out of Space" );

		PreNode->Next = NULL;
		T[ i ].Header = PreNode;

		for( j = 0; j < NumVertex; j++ )
		{
			if( G[ i ][ j ] != 0 )	
			{
				Node = malloc( sizeof( struct AdjVNode ) );
				if( Node == NULL )
					perror( "Out of Space" );

				Node->AdjV   = j;
				Node->Weight = G[ i ][ j ];
				Node->Next   = NULL;

				PreNode->Next = Node;
				PreNode       = Node;
			}
		}
	}
}

void 
PrintPath( Vertex V, Table T )
{
	if( T[ V ].Path != NotAVertex )
	{
		PrintPath( T[ V ].Path, T );
		printf( " to " );
	}
	printf( "%d", V );
}

void 
Dijkstra( Table T )
{
	Vertex V, W;

	PtrToAdjVNode Node;

	for( ; ; )
	{
		V = FindSmallestUnkownVertex( T );	
		if( V == NotAVertex )
			break;

		T[ V ].Known = True;

		Node = T[ V ].Header->Next;
		while( Node )
		{
			W = Node->AdjV;
			if( T[ V ].Dist + Node->Weight < T[ W ].Dist )
			{
				T[ W ].Dist = T[ V ].Dist + Node->Weight;
				T[ W ].Path = V;
			}
			Node = Node->Next;
		}
	}
}

static Vertex 
FindSmallestUnkownVertex( Table T )
{
	Vertex MinVertex = NotAVertex;
	WeightType MinWeight = Infinity;
	int i;

	for( i = 0; i < NumVertex; i++ )
	{
		if( !T[ i ].Known && T[ i ].Dist < MinWeight )
		{
			MinVertex = i;
			MinWeight = T[ i ].Dist;
		}
	}

	return MinVertex;
}

WeightType 
PathWeight( Vertex V, Table T )
{
	return T[ V ].Dist;
}
