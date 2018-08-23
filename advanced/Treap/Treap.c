#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "Treap.h"

#define Infinity ( INT_MAX )

struct TreapNode
{
	ElementType Element;
	Treap       Left;
	Treap       Right;
	int         Priority;
};

int 
Random( int M )
{
	return rand() % M;
}

static Treap NullNode = NULL;

static Position SingleRotateWithLeft( Position K2 );
static Position SingleRotateWithRight( Position K2 );

Treap 
Initialize( void )
{
	if( NullNode == NULL )
	{
		NullNode = malloc( sizeof( struct TreapNode ) );
		if( NullNode == NULL )
			perror( "Out of Space" );
		NullNode->Left = NullNode->Right = NullNode;
		NullNode->Priority = Infinity;
	}
	return NullNode;
}

Treap 
Insert( ElementType Item, Treap T )
{
	if( T == NullNode )
	{
		/* Create and return a one node tree */
		T = malloc( sizeof( struct TreapNode ) );
		if( T == NULL )
			perror( "Out of space" );
		else
		{
			T->Element = Item; T->Priority = Random( 71 );	
			T->Left = T->Right = NullNode;
		}
	}
	else
	if( Item < T->Element )
	{
		T->Left = Insert( Item, T->Left );	
		if( T->Left->Priority < T->Priority )
			T = SingleRotateWithLeft( T );
	}
	else
	if( Item > T->Element )
	{
		T->Right = Insert( Item, T->Right );
		if( T->Right->Priority < T->Priority )
			T = SingleRotateWithRight( T );
	}
	/* Otherwise it's a duplicate; do nothing */

	return T;
}

Treap 
Remove( ElementType Item, Treap T )
{
	if( T != NullNode )
	{
		if( Item < T->Element )	
			T->Left = Remove( Item, T->Left );
		else 
		if( Item > T->Element )
			T->Right = Remove( Item, T->Right );
		else
		{
			/* Match found */
			if( T->Left->Priority < T->Right->Priority )
				T = SingleRotateWithLeft( T );
			else
				T = SingleRotateWithRight( T );

			if( T != NullNode )
				T = Remove( Item, T );
			else
			{
				free( T->Left );
				T->Left = NullNode;
			}
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
Find( ElementType X, Treap T )
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

Treap
FindMin( Treap T )
{
	if( T != NullNode )
		while( T->Left != NullNode )
			T = T->Left;
	return T;
}

Treap 
FindMax( Treap T )
{
	if( T != NullNode )
		while( T->Right != NullNode )
			T = T->Right;
	return T;
}

