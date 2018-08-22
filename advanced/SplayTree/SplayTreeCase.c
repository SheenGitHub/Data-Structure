#include <stdio.h>
#include "SplayTree.h"

int main()
{
	SplayTree T;
	T = Initialize();
	int i;
	ElementType Value;


	for( i = 0; i < 16; i++ )
	{
		T = Insert( i + 1, T );
	}

	for( i = 0; i < 16; i++ )
	{
		T = FindMax( T );
		Value = Retrieve( T );
		printf( "%d\n", Value );
		T = Remove( Value, T );
	}
}
