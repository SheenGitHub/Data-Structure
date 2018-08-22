#include <stdio.h>
#include <stdlib.h>
#include "LeftHeap.h"

static void SwapChildren( PriorityQueue H );
static PriorityQueue Merge1( PriorityQueue H1, PriorityQueue H2 );
struct TreeNode
{
	ElementType   Element;
	PriorityQueue Left;
	PriorityQueue Right;
	int           Npl;
};

PriorityQueue
Merge( PriorityQueue H1, PriorityQueue H2 )
{
	if( H1 == NULL )
		return H2;
	if( H2 == NULL )
		return H1;
	if( H1->Element < H2->Element )
		return Merge1( H1, H2 );
	else
		return Merge1( H2, H1 );
}

static PriorityQueue
Merge1( PriorityQueue H1, PriorityQueue H2 )
{
	if( H1->Left == NULL )
		H1->Left = H2;
	else
	{
		H1->Right = Merge( H1->Right, H2 );
		if( H1->Left->Npl < H1->Right->Npl )
			SwapChildren( H1 );
		
		H1->Npl = H1->Right->Npl + 1;
	}
	return H1;
}

PriorityQueue
Insert1( ElementType X, PriorityQueue H )
{
	PriorityQueue SingleNode;

	SingleNode = malloc( sizeof( struct TreeNode ) );
	if( SingleNode == NULL )
		perror( "Out of space" );
	else
	{
		SingleNode->Element = X;
		SingleNode->Npl = 0;
		SingleNode->Left = SingleNode->Right = NULL;
		H = Merge( SingleNode, H );
	}
	return H;
}

/* DeleteMin1 returns the new tree */
/* To get the minimum, use findMin */
/* This is for convenience */

PriorityQueue
DeleteMin1( PriorityQueue H )
{
	PriorityQueue LeftHeap, RightHeap;
	if( IsEmpty( H ) )
	{
		printf( "Priority queue is empty\n" );	
		return H;
	}

	LeftHeap  = H->Left;
	RightHeap = H->Right;
	free( H );
	return Merge( LeftHeap, RightHeap );
}

static void
SwapChildren( PriorityQueue H )
{
	PriorityQueue Tmp;

	if( H == NULL )
		return;
	Tmp = H->Left;
	H->Left = H->Right;
	H->Right = Tmp;
}

int
IsEmpty( PriorityQueue H )
{
	return H == NULL;
}

void PrintElement( PriorityQueue H )
{
	if( H != NULL )
		printf( "Element %d, Npl %d\n", H->Element, H->Npl );
}


