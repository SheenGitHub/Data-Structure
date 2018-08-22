#include <stdio.h>
#include <stdlib.h>
#include "HashSep.h"
#include "Hash.h"
HashTable
InitializeTable( int TableSize )
{
	HashTable H;
	int i;

	if( TableSize < MinTableSize )
	{
		perror( "Table size too small." );
		return NULL;
	}

	/* Allocate table */
	H = malloc( sizeof( struct HashTbl ) );
	if( H == NULL )
		perror( "Out of space" );

	H->TableSize = NextPrime( TableSize );
	printf( "TableSize: %d\n", H->TableSize );

	/* Allocate array of lists */
	H->TheLists = malloc( sizeof( List ) * H->TableSize );
	if( H->TheLists == NULL )
		perror( "Out of space" );

	/* Allocate list headers */
	for( i = 0; i < H->TableSize; i++ )
	{
		H->TheLists[ i ] = malloc( sizeof( struct ListNode ) );
		if( H->TheLists[ i ] == NULL )
			perror( "Out of space" );
		else
			H->TheLists[i]->Next = NULL;
	}
		printf( "Initialized Table:\n" );

	return H;
}

Position
Find( ElementType Key, HashTable H )
{
	Position P;
	List L;
	printf( "hashCode:%d\n", Hash( Key, H->TableSize ) );
	L = H->TheLists[ Hash( Key, H->TableSize ) ];
	P = L->Next;
	while( P != NULL && P->Element != Key )
		P = P->Next;
	return P;
}

void Insert( ElementType Key, HashTable H )
{
	Position Pos, NewCell;
	List L;

	Pos = Find( Key, H );
	if( Pos == NULL )
	{
		printf( "Insert New %d\n",Key );
		NewCell = malloc( sizeof( struct ListNode ) );
		if( NewCell == NULL )
			perror( "Out of space" );
		else
		{
			printf( "Insert HashCode %d of %d\n", Hash( Key, H->TableSize ), Key );
			L = H->TheLists[ Hash( Key, H->TableSize ) ];
			NewCell->Next = L->Next;
			NewCell->Element = Key;
			L->Next = NewCell;
		}
	}
}
