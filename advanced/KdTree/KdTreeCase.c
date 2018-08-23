#include <stdio.h>
#include "KdTree.h"

int main()
{
	KdTree T = NULL;
	ItemType input[] = {
		{ 53, 14 }, { 27, 28 }, { 67, 50 },
		{ 30, 11 }, { 31, 85 }, { 79, 3 }, { 99, 90 },
		{ 29, 16 }, { 40, 26 }, { 7, 39 }, { 32, 29 },
		{ 82, 64 }, { 38, 23 }, { 15, 61 }, { 73, 75 },
	};
	int i;
	for( i = 0; i < 15; i++ )
	{
		T = Insert( input[ i ], T );	
	}

	ItemType Low = { 24, 23 };
	ItemType High = { 70, 63 };
	printf( "Between ( %d, %d ) and ( %d, %d ):\n", Low[ 0 ], Low[ 1 ], High[ 0 ], High[ 1 ] );
	PrintRange( Low, High, T );
}
