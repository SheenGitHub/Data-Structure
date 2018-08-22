#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "RedBlackTree.h"

#define Infinity (INT_MAX)
#define NegInfinity (INT_MIN)

struct RedBlackNode
{
	ElementType  Element;
	RedBlackTree Left;
	RedBlackTree Right;
	ColorType    Color;
};
typedef struct RedBlackNode *Position;

static Position SingleRotateWithLeft( Position K2 );
static Position SingleRotateWithRight( Position K2 );

Position NullNode = NULL;

RedBlackTree 
Initialize( void )
{
	RedBlackTree T;
	if( NullNode == NULL )
	{
		NullNode = malloc( sizeof( struct RedBlackNode ) );
		if( NullNode == NULL )
			perror( "Out of Space" );
		NullNode->Left = NullNode->Right = NullNode;
		NullNode->Color = Black;
		NullNode->Element = Infinity;
	}

	T = malloc( sizeof( struct RedBlackNode ) );
	if( T == NULL )
		perror( "Out of Space" );
	T->Element = NegInfinity;
	T->Left = T->Right = NullNode;
	T->Color = Black;

	return T;
}

static Position 
Rotate( ElementType Item, Position Parent )
{
	if( Item < Parent->Element )
		return Parent->Left = Item < Parent->Left->Element ? 
			SingleRotateWithLeft( Parent->Left ) : 
			SingleRotateWithRight( Parent->Left );
	else
		return Parent->Right = Item < Parent->Right->Element ?
			SingleRotateWithLeft( Parent->Right ) :
			SingleRotateWithRight( Parent->Right );
}

static Position X, P, GP, GGP;

static 
void HandleReorient( ElementType Item, RedBlackTree T )
{
	X->Color = Red;
	X->Left->Color = Black;
	X->Right->Color = Black;

	if( P->Color == Red )
	{
		GP->Color = Red;
		if( ( Item < GP->Element ) != ( Item < P->Element ) )
			P = Rotate( Item, GP );
		X = Rotate( Item, GGP );
		X->Color = Black;
	}
	T->Right->Color = Black;
}

RedBlackTree 
Insert( ElementType Item, RedBlackTree T )
{
	X = P = GP = T;
	NullNode->Element = Item;
	while( X->Element != Item )
	{
		GGP = GP; GP = P; P = X;
		if( Item < X->Element )
			X = X->Left;
		else
			X = X->Right;
		if( X->Left->Color == Red && X->Right->Color == Red )
			HandleReorient( Item, T );
	}

	if( X != NullNode )
		return NullNode;
	
	X = malloc( sizeof( struct RedBlackNode ) );
	if( X == NULL )
		perror( "Out of space!!!" );
	X->Element = Item;
	X->Left = X->Right = NullNode;

	if( Item < P->Element )
		P->Left = X;
	else
		P->Right = X;
	HandleReorient( Item, T );
	NullNode->Element = Infinity;
	return T;
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

RedBlackTree 
MakeEmpty( RedBlackTree T )
{
	if( T != NullNode )
	{
		MakeEmpty( T->Left );
		MakeEmpty( T->Right );
		free( T );
	}
	return NullNode;
}

Position
Find( ElementType X, RedBlackTree T )
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

RedBlackTree
FindMin( RedBlackTree T )
{
	if( T != NullNode )
		while( T->Left != NullNode )
			T = T->Left;
	return T;
}

RedBlackTree 
FindMax( RedBlackTree T )
{
	if( T != NullNode )
		while( T->Right != NullNode )
			T = T->Right;
	return T;
}

ElementType 
Retrieve( RedBlackTree T )
{
	return T->Element;
}

static void 
Output( RedBlackTree T )
{
	char * color;
	if( T->Color == Red )	
		color = "Red";
	else if( T->Color == Black )
		color = "Black";
	printf( "%d %s\n", T->Element, color );
}

static void 
DoPrint( RedBlackTree T )
{
	if( T != NullNode )
	{
		DoPrint( T->Left );
		Output( T );
		DoPrint( T->Right );
	}
}

void 
PrintTree( RedBlackTree T )
{
	DoPrint( T->Right );
}

static void 
DoPrePrint( RedBlackTree T )
{
	if( T != NullNode )
	{
		Output( T );
		DoPrePrint( T->Left );
		DoPrePrint( T->Right );
	}
}

void 
PrintPreTree( RedBlackTree T )
{
	DoPrePrint( T->Right );
}
