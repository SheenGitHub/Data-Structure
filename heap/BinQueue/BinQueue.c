#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "BinQueue.h"

struct BinNode
{
	ElementType Element;
	Position    LeftChild;
	Position    NextSibling;
};

struct Collection
{
	int CurrentSize;
	BinTree TheTrees[ MaxTrees ];
};

BinQueue 
Initialize( )
{
	BinQueue H;
	H = malloc( sizeof( struct Collection ) );
	if( H == NULL )
		perror( "Out of Space" );

	int i ;
	//Set H->TheTrees elements NULL
	for( i = 0; i < MaxTrees; i++ )
		 H->TheTrees[i] = NULL;
	H->CurrentSize = 0;

	return H;
}

int
IsEmpty( BinQueue H )
{
	return H->CurrentSize == 0;
}

BinTree
CombineTrees( BinTree T1, BinTree T2 )
{
	if( T1->Element > T2->Element )
		return CombineTrees( T2, T1 );
	T2->NextSibling = T1->LeftChild;
	T1->LeftChild = T2;
	return T1;
}

BinQueue
Merge( BinQueue H1, BinQueue H2 )
{
	BinTree T1, T2, Carry = NULL;
	int i, j;
	if( H1->CurrentSize + H2->CurrentSize > Capacity )
		printf( "Merge would exceed capacity\n" );
		
	H1->CurrentSize += H2->CurrentSize;
	for( i = 0, j = 1; j <= H1->CurrentSize; i++, j *= 2 )
	{
		T1 = H1->TheTrees[ i ];
		T2 = H2->TheTrees[ i ];
		switch( !!T1 + 2 * !!T2 + 4 * !!Carry )
		{
			case 0: /* No Trees */
			case 1: /* Only H1 */
				break;
			case 2: /* Only H2 */
				H1->TheTrees[ i ] = T2;
				H2->TheTrees[ i ] = NULL;
				break;
			case 4: /* Only Carry */
				H1->TheTrees[ i ] = Carry;
				Carry = NULL;
				break;
			case 3: /* H1 and H2 */
				Carry = CombineTrees( T1, T2 );
				H1->TheTrees[ i ] = H2->TheTrees[ i ] = NULL;
				break;
			case 5: /* H1 and Carry */
				Carry = CombineTrees( T1, Carry );
				H1->TheTrees[ i ] = NULL;
				break;
			case 6: /* H2 and Carry */
				Carry = CombineTrees( T2, Carry );
				H2->TheTrees[ i ] = NULL;
				break;
			case 7: /* All Tree */
				H1->TheTrees[ i ] = Carry;
				Carry = CombineTrees( T1, T2 );
				H2->TheTrees[ i ] = NULL;
				break;
		}
	}
	return H1;
}

ElementType 
DeleteMin( BinQueue H )
{
	int i, j;
	int MinTree; /* The tree with the minimum item */ 
	BinQueue DeletedQueue;
	Position DeletedTree, OldRoot;
	ElementType MinItem;

	if( IsEmpty( H ) )
	{
		printf( "Empty binomial queue\n" );
		return INT_MIN;
	}

	MinItem = INT_MAX;
	for( i = 0; i < MaxTrees; i++ )
	{
		if( H->TheTrees[ i ] && H->TheTrees[ i ]->Element < MinItem )
		{
			
			MinItem = H->TheTrees[ i ]->Element;
			MinTree = i;
		}
	}

	DeletedTree  = H->TheTrees[ MinTree ];
	OldRoot     = DeletedTree;
	DeletedTree = DeletedTree->LeftChild;
	free( OldRoot );

	DeletedQueue = Initialize();
	DeletedQueue->CurrentSize = ( 1 << MinTree ) - 1;
	for( j = MinTree - 1; j >= 0; j-- )
	{
		DeletedQueue->TheTrees[ j ] = DeletedTree;
		DeletedTree = DeletedTree->NextSibling;
		DeletedQueue->TheTrees[ j ]->NextSibling = NULL;
	}

	H->TheTrees[ MinTree ] = NULL;
	H->CurrentSize -= DeletedQueue->CurrentSize + 1;

	Merge( H, DeletedQueue );
	return MinItem;
}

BinQueue 
Insert( ElementType X, BinQueue H )
{
	BinTree T;
	BinQueue Tmp;
	
	T = malloc( sizeof( struct BinNode ) );
	if( T == NULL )
		perror( "Out of Space" );
	
	T->Element = X;
	T->LeftChild = T->NextSibling = NULL;
	
	Tmp = Initialize();

	Tmp->TheTrees[ 0 ] = T;
	Tmp->CurrentSize = 1;
	if( H == NULL )
		return Tmp;

	H = Merge( H, Tmp );
	return H;
}
