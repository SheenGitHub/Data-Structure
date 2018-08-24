#include <stdio.h>
#include "PairHeap.h"
int main()
{
	PairHeap H = NULL;
	Position P;
	int i;
	ElementType Value;
	for( i = 0; i < 16; i++ )
	{
		H = Insert( i + 1, H, &P );
	}

	for( i = 0; i < 16; i++ )
	{
		H = DeleteMin( &Value, H );
		printf( "Delete Min %d\n", Value );
	}
}
