#include "Sort.h"
#define Cutoff ( 3 )

static void 
Swap( ElementType * A, ElementType * B )
{
	ElementType Tmp;
	Tmp = *A;
	*A   = *B;
	*B   = Tmp;
}

ElementType 
Median3( ElementType A[], int Left, int Right )
{
	int Center = ( Left + Right ) / 2;

	if( A[ Left ] > A[ Center ] )
		Swap( &A[ Left ], &A[ Center ] );
	if( A[ Left ] > A[ Right ] )
		Swap( &A[ Left ], &A[ Right ] );
	if( A[ Center ] > A[ Right ] )
		Swap( &A[ Center ], &A[ Right ] );

	Swap( &A[ Center ], &A[ Right - 1 ] );
	return A[ Right - 1 ];
}

void
QSelect( ElementType A[], int k, int Left, int Right )
{
	int i, j;
	ElementType Pivot;

	if( Left + Cutoff <= Right )
	{
		Pivot = Median3( A, Left, Right );
		i = Left; j = Right - 1;
		for( ; ; )
		{
			while( A[ ++i ] < Pivot ){}
			while( A[ --j ] > Pivot ){}
			if( i < j )
				Swap( &A[ i ], &A[ j ] );
			else
				break;
		}
		Swap( &A[ i ], &A[ Right - 1 ] );

		if( k <= i )
			QSelect( A, k, Left, i - 1 );
		else if( k > i + 1 )
			QSelect( A, k, i + 1, Right );
	}
	else
		InsertionSort( A + Left, Right - Left + 1 );
}

ElementType 
QuickSelect( ElementType A[], int k, int N )
{
	QSelect( A, k, 0, N - 1 );
	return A[ k - 1 ];
}
