#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "HuffmanTree.h"
#include "BinHeap.h"

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
	H->Elements[ 0 ] = malloc( sizeof( HuffmanNode ) );
	H->Elements[ 0 ]->Freq = -1;

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

	for( i = ++H->Size; H->Elements[ i / 2 ]->Freq > X->Freq; i /= 2 )
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
		if( Child != H->Size && H->Elements[ Child + 1 ]->Freq < H->Elements[ Child ]->Freq )
		Child++;


		if( LastElement->Freq > H->Elements[ Child ]->Freq )
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
		printf( "%d->%d \n", i, H->Elements[i]->Freq );
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
		if( Child != H->Size && H->Elements[ Child + 1 ]->Freq < H->Elements[ Child ]->Freq )
			Child++;
		if( H->Elements[ Child ]->Freq < Tmp->Freq )
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
ReadNodeIntoHeapArray( CharList Nodes, PriorityQueue H, int CharNum )
{
	int i;
	for( i = 1; i <= CharNum; i++ )
	{
		H->Elements[ i ]        = malloc( sizeof( HuffmanNode) );
		if( H->Elements[ i ] == NULL )
			perror( "Out of space" );

		H->Elements[ i ]->Code  = Nodes[ i ].Code;
		H->Elements[ i ]->Freq  = Nodes[ i ].Freq;
		H->Elements[ i ]->Left  = NULL;
		H->Elements[ i ]->Right = NULL;
		H->Size++;
	}
}

int
IsOnly( PriorityQueue H )
{
	return H->Size == 1;
}
