#include <stdio.h>

void 
PercolateDown( int hole, int H[], int N)
{
	int Child;
	int Tmp = H[ hole ];
	for( ; hole * 2 <= N; hole = Child )
	{
		Child = hole * 2;
		if( Child != N && H[ Child + 1 ] < H[ Child ] )
			Child++;
		if( H[ Child ] < Tmp )
			H[ hole ] = H[ Child ];
		else
			break;
	}
	H[ hole ] = Tmp;
}

int main()
{
	int arr[] = { 0, 150, 80, 40, 30, 10, 70, 110, 100, 20, 90, 60, 50, 120, 140, 130 };
	int i, N = 15;
	
	for( i = N/2; i > 0; i-- )
		PercolateDown( i, arr, N );
	
	for( i = 1; i <= 15; i++ )
		printf( "%d ",arr[ i ] );
	printf( "\n" );
}

