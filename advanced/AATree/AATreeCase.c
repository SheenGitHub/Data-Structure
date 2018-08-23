#include <stdio.h>
#include "AATree.h"
int main()
{
	AATree T;
	Position P;
	int i;
	T = Initialize();
	for( i = 0; i < 16; i++ )
	{
		T = Insert( i + 1, T );
	}
	T = Remove( 7, T );
	T = Remove( 1, T );
	T = Remove( 16, T );
	P = FindMax( T );
	printf( "Find Max %d\n", Retrieve( P ) );
	P = FindMin( T );
	printf( "Find Min %d\n", Retrieve( P ) );
	P = Find( 7, T );
	printf( "Find 7 %d\n", Retrieve( P ) );
}
