#include <stdio.h>
#include "DisjSet.h"

int main()
{
	int i, value;
	DisjSet S;
	Initialize( S );
	SetUnion( S, 5, 6 );
	SetUnion( S, 7, 8 );
	SetUnion( S, 5, 7 );
	SetUnion( S, 4, 5 );

	for( i = 1; i <= NumSets; i++  )
	{
		value = Find( i, S );
		printf( "%d root %d\n", i, value );
	}

	for( i = 1; i <= NumSets; i++  )
	{
		printf( "%d parent %d\n", i, S[ i ] );
	}
	
	
}
