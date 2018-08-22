#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "BinHeap.h"
#include "Graph.h"

struct HeapStruct
{
	int Capacity;
	int Size;
	HeapElemType *Elements;
};

PriorityQueue
InitializeHeap( int MaxElements )
{
	PriorityQueue H;
	HeapElemType MinEdge;

	if( MaxElements < MinPQSize )
		perror( "Priority queue size is too small\n" );
	
	H = malloc( sizeof( struct HeapStruct ) );
	if( H == NULL )
		perror( "Out of space" );
	
	H->Elements = malloc( ( MaxElements + 1 ) * sizeof( HeapElemType ) );

	if( H->Elements == NULL )
		perror( "Out of space!!!" );

	H->Capacity = MaxElements;
	H->Size = 0;
	H->Elements[ 0 ].Weight = INT_MIN;

	return H;
}

void
Insert( HeapElemType X, PriorityQueue H )
{
	int i;

	if( IsFull( H ) )
	{
		perror( "priority queue is full" );
		return;
	}

	for( i = ++H->Size; H->Elements[ i / 2 ].Weight > X.Weight; i /= 2 )
		H->Elements[ i ] = H->Elements[ i / 2 ];
	H->Elements[ i ] = X;
}

HeapElemType
DeleteMin( PriorityQueue H )
{
	int i, Child;
	HeapElemType MinElement, LastElement;

	if( IsEmpty( H ) )
	{
		perror( "Priority queue is empty" );
		return H->Elements[ 0 ];
	}
	MinElement = H->Elements[ 1 ];
	LastElement = H->Elements[ H->Size-- ];

	for( i = 1; i * 2 <= H->Size; i = Child )
	{
		Child = i * 2;
		if( Child != H->Size && H->Elements[ Child + 1 ].Weight < H->Elements[ Child ].Weight )
		Child++;


		if( LastElement.Weight > H->Elements[ Child ].Weight )
			H->Elements[ i ] = H->Elements[ Child ];
		else
			break;
	}

	H->Elements[ i ] = LastElement;
	return MinElement;
}

int 
IsEmpty( PriorityQueue H )
{
	return H->Size == 0;
}

int 
IsFull( PriorityQueue H )
{
	return H->Size == H->Capacity;
}

void PrintHeap( PriorityQueue H )
{
	int i;
	for( i = 1; i <= H->Size; i++ )
		printf( "%d->%d (%d) \n", H->Elements[i].V, H->Elements[i].U, H->Elements[i].Weight );
	printf( "\n" );
}

typedef int Index;

static void 
PercolateDown( Index hole, PriorityQueue H )
{
	int Child;
	HeapElemType Tmp = H->Elements[ hole ];
	for( ; hole * 2 <= H->Size; hole = Child )
	{
		Child = hole * 2;
		if( Child != H->Size && H->Elements[ Child + 1 ].Weight < H->Elements[ Child ].Weight )
			Child++;
		if( H->Elements[ Child ].Weight < Tmp.Weight )
			H->Elements[ hole ] = H->Elements[ Child ];
		else
			break;
	}
	H->Elements[ hole ] = Tmp;
}

void 
BuildHeap( PriorityQueue H )
{
	int i;
	for( i = H->Size / 2; i > 0; i-- )
	{
		PercolateDown( i, H );
	}
}

void 
ReadGraphIntoHeapArray( Graph G, PriorityQueue H, int NumEdges )
{
	int i;
	for( i = 0; i < NumEdges; i++ )
	{
		H->Elements[ i + 1 ].V = G[ i ][ 0 ];
		H->Elements[ i + 1 ].U = G[ i ][ 1 ];
		H->Elements[ i + 1 ].Weight = G[ i ][ 2 ];
		H->Size++;
	}
}
