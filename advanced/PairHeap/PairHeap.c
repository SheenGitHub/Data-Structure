#include <stdio.h>
#include <stdlib.h>
#include "PairHeap.h"

#define MaxSibling ( 30 )

struct PairNode
{
	PairHeap    LeftChild;
	PairHeap    NextSibling;
	PairHeap    Prev;
	ElementType Element;
};

/* This is the basic opeartion to maintain order */
/* Links First and Second together to satisfy heap order */
/* Returns the resulting tree */
/* First is assumed NOT NULL */
/* First->NextSibling MUST be NULL on entry */
Position 
CompareAndLink( Position First, Position Second )
{
	if( Second == NULL )
		return First;
	else 
	if( First->Element <= Second->Element )
	{
		/* Attach Second as the leftmost child of First */
		Second->Prev = First;
		First->NextSibling = Second->NextSibling;
		if( First->NextSibling != NULL )
			First->NextSibling->Prev = First;
		Second->NextSibling = First->LeftChild;
		if( Second->NextSibling != NULL )
			Second->NextSibling->Prev = Second;
		First->LeftChild = Second;
		return First;
	}
	else
	{
		/* Attach First as the leftmost child of Second */	
		Second->Prev = First->Prev;
		First->Prev = Second;
		First->NextSibling = Second->LeftChild;
		if( First->NextSibling != NULL )
			First->NextSibling->Prev = First;
			Second->LeftChild = First;
			return Second;
	}
}

/* Insert Item into pairing heap H */
/* Return resulting pairing heap */
/* A pointer go the newly allocated node */
/* is passed back by reference and accessed as *Loc */
PairHeap 
Insert( ElementType Item, PairHeap H, Position *Loc )
{
	Position NewNode;
	
	NewNode = malloc( sizeof( struct PairNode ) );
	if( NewNode == NULL )
		perror( "Out of Space" );
	NewNode->Element = Item;
	NewNode->LeftChild = NewNode->NextSibling = NULL;
	NewNode->Prev = NULL;

	*Loc = NewNode;
	if( H == NULL )
		return NewNode;
	else
		return CompareAndLink( H, NewNode );
}

/* Lower item in the Position P by Delta */

PairHeap 
DecreaseKey( Position P, ElementType Delta, PairHeap H)
{
	if( Delta < 0 )
		printf( "DecreaseKey called with negative Delta" );

	P->Element -= Delta;
	if( P == H )
		return H;
	
	if( P->NextSibling != NULL )
		P->NextSibling->Prev = P->Prev;
	if( P->Prev->LeftChild == P )
		P->Prev->LeftChild = P->NextSibling;
	else
		P->Prev->NextSibling = P->NextSibling;
	P->NextSibling = NULL;
	return CompareAndLink( H, P );
}

PairHeap 
DeleteMin( ElementType *MinItem, PairHeap H )
{
	Position NewRoot = NULL;

	if( H == NULL )
		printf( "Pairing heap is empty" );
	else
	{
		*MinItem = H->Element;
		if( H->LeftChild != NULL )
			NewRoot = CombineSiblings( H->LeftChild );
		free( H );
	}
	return NewRoot;
}

/* Assumes FirstSibling is NOT NULL */

PairHeap
CombineSiblings( Position FirstSibling )
{
	static Position TreeArray[ MaxSibling ];
	int i, j, NumSiblings;

	/* If only one tree, return i */
	if( FirstSibling->NextSibling == NULL )
		return FirstSibling;
	
	/* Place each subtree in TreeArray */
	for( NumSiblings = 0; FirstSibling != NULL; NumSiblings++ )
	{
		TreeArray[ NumSiblings ] = FirstSibling;
		FirstSibling->Prev->NextSibling = NULL;
		FirstSibling = FirstSibling->NextSibling;
	}
	TreeArray[ NumSiblings ] = NULL;

	/* Combine the subtrees two at a time, */
	/* going left to right */
	for( i = 0; i + 1 < NumSiblings; i += 2 )
		TreeArray[ i ] = CompareAndLink( TreeArray[ i ], TreeArray[ i + 1 ] );

	/* j has the result of the last CompareAndLink */
	/* If and odd number of trees, get the last one */
	j = i - 2;
	if( j == NumSiblings - 3 )
		TreeArray[ j ] = CompareAndLink( TreeArray[ j ], TreeArray[ j + 2 ] );
	/* Now go right to left, merging last tree with */
	/* next to last. The result becomes the new last */
	for( ; j >= 2; j -= 2 )
		TreeArray[ j - 2 ] = CompareAndLink( TreeArray[ j - 2 ], TreeArray[ j ] );

	return TreeArray[ 0 ];
}

ElementType 
Retrieve( Position P )
{
	return P->Element;
}
