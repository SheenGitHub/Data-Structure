#include <stdio.h>
#include "SkipList.h"
int main()
{
	SkipList L;
	Position P;
	L = Initialize();
	int i;
	for( i = 0; i < 16; i++ )
	{
		L = Insert( i + 1, L );
	}

	for( i = 0; i < 16; i++ )
	{
		P = Find( i + 1, L );
		printf( "Find %d\n", Retrieve( P ) );
	}
}
