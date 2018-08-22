#include <stdio.h>
#include <stdlib.h>
#include "AdjTable.h"

static void ReadGraph( Graph, Table );
static int Counter = 0;
static int Min( int, int );

void 
InitTable( Graph G, Table T )
{
	int i;
	ReadGraph( G, T );
	for( i = 0; i < NumVertex; i++ )
	{
		T[ i ].Visited = False;
		T[ i ].Low     = NotAVertex;
		T[ i ].Number  = -1;
		T[ i ].Parent  = NotAVertex;
	}
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
				Node->Next   = NULL;

				PreNode->Next = Node;
				PreNode       = Node;
			}
		}
	}
}

void 
FindArt( Vertex V, Table T )
{
	Vertex W;

	PtrToAdjVNode Node;

	T[ V ].Visited = True;
	T[ V ].Low = T[ V ].Number = Counter++;
	
	Node = T[ V ].Header->Next;
	while( Node )
	{
		W = Node->AdjV;
		if( !T[ W ].Visited )
		{
			T[ W ].Parent = V;
			FindArt( W, T );
			if( T[ W ].Low >= T[ V ].Number )
				printf( "%d is an articulation point\n", V );
			T[ V ].Low = Min( T[ V ].Low, T[ W ].Low  );
		}
		else
		{
			if( T[ V ].Parent != W )
			{
				T[ V ].Low = Min( T[ V ].Low, T[ W ].Number );
			}
		}
		Node = Node->Next;
	}
}

int 
Min( int A, int B)
{
	return A < B ? A : B;
}

int 
main()
{
	Graph 
	Input = 
	{
		0, 1, 0, 1, 0, 0, 0,
		1, 0, 1, 0, 0, 0, 0,
		0, 1, 0, 1, 0, 0, 1,
		1, 0, 1, 0, 1, 1, 0,
		0, 0, 0, 1, 0, 1, 0,
		0, 0, 0, 1, 1, 0, 0,
		0, 0, 1, 0, 0, 0, 0
	};
	Table T, T1;
	int i;

	InitTable( Input, T);
	FindArt( 0, T );
	printf( "Test From 3\n" );
	InitTable( Input, T1);
	FindArt( 3, T1 );
}
