#include <stdio.h>
#include <stdlib.h>
#include "AATree.h"

struct AANode
{
	ElementType Element;
	AATree      Left;
	AATree      Right;
	int         Level;
};

Position NullNode = NULL;

static Position SingleRotateWithLeft( Position K2 );
static Position SingleRotateWithRight( Position K2 );

AATree 
Initialize( void )
{
	if( NullNode == NULL )
	{
		NullNode = malloc( sizeof( struct AANode ) );
		if( NullNode == NULL )
			perror( "Out of Space!!!" );
		NullNode->Left = NullNode->Right = NullNode;
		NullNode->Level = 0;
	}
	return NullNode;
}

static AATree 
Skew( AATree T )
{
	if( T->Left->Level == T->Level )
		T = SingleRotateWithLeft( T );
	return T;
}

static AATree 
Split( AATree T )
{
	if( T->Right->Right->Level == T->Level )
	{
		T = SingleRotateWithRight( T );
		T->Level++;
	}
	return T;
}

AATree
Insert( ElementType Item, AATree T )
{
	if( T == NullNode )
	{
		T = malloc( sizeof( struct AANode ) );
		if( T == NULL )
			perror( "Out of Space" );
		else
		{
			T->Element = Item; T->Level = 1;
			T->Left = T->Right = NullNode;
		}
		return T;
	}
	else
	if( Item < T->Element )
		T->Left = Insert( Item, T->Left );
	else
	if( Item > T->Element )
		T->Right = Insert( Item, T->Right );
	
	/* Otherwise it's a duplicate; do nothing */

	T = Skew( T );
	T = Split( T );
	return T;
}

AATree 
Remove( ElementType Item, AATree T )
{
	static Position DeletePtr, LastPtr;
	if( T != NullNode )
	{
		/* Step 1: Search down tree */
		/*         set LastPtr and DeletePtr */
		LastPtr = T;
		if( Item < T->Element )
			T->Left = Remove( Item, T->Left );
		else 
		{
			DeletePtr = T;
			T->Right = Remove( Item, T->Right );
		}

		/* Step 2: If at the bottom of the tree and */
		/*         item is present, we remove it */
		if( T == LastPtr )
		{
			if( DeletePtr != NullNode && 
				Item == DeletePtr->Element )
			{
				DeletePtr->Element = T->Element;
				DeletePtr = NullNode;
				T = T->Right;
				free( LastPtr );
			}
		}

		/* Step 3: Otherwise, we are not at the bottom;  */
		/*         rebalance */
		else
			if( T->Left->Level < T->Level -1 ||
				T->Right->Level < T->Level - 1 )
			{
				if( T->Right->Level > --T->Level )	
					T->Right->Level = T->Level;
				T = Skew( T );
				T->Right = Skew( T->Right );
				T->Right = Skew( T->Right->Right );
				T = Split( T );
				T->Right = Split( T->Right );
			}
	}
	return T;
}

ElementType
Retrieve( Position P )
{
	if( P != NullNode )
		return P->Element;
	else 
		return -123456;
}

static Position
SingleRotateWithLeft( Position K2 )
{
	Position K1;

	K1 = K2->Left;
	K2->Left = K1->Right;
	K1->Right = K2;

	return K1;
}

static Position
SingleRotateWithRight( Position K2 )
{
	Position K1;

	K1 = K2->Right;
	K2->Right = K1->Left;
	K1->Left = K2;

	return K1;
}

Position
Find( ElementType X, AATree T )
{
	if( T == NullNode )
		return NullNode;
	if( X < T->Element )
		return Find( X, T->Left );
	else
	if( X > T->Element )
		return Find( X, T->Right );
	else
		return T;
}

AATree
FindMin( AATree T )
{
	if( T != NullNode )
		while( T->Left != NullNode )
			T = T->Left;
	return T;
}

AATree 
FindMax( AATree T )
{
	if( T != NullNode )
		while( T->Right != NullNode )
			T = T->Right;
	return T;
}
