#include <stdio.h>
#define NumMatrix (6)
#define Infinity (99999)

typedef int TwoDimArray[ NumMatrix + 1 ][ NumMatrix + 1 ];

void
OptMatrix( const long C[], int N, TwoDimArray M, TwoDimArray LastChange )
{
	int i, k, Left, Right;
	long ThisM;

	for( Left = 1; Left <= N; Left++ )
		M[ Left ][ Left ] = 0;
	for( k = 1; k < N; k++ )
		for( Left = 1; Left <= N - k; Left++ )
		{
			Right = Left + k;
			M[ Left ][ Right ] = Infinity;
			for( i = Left; i < Right; i++ )
			{
				ThisM = M[ Left ][ i ] + M[ i + 1 ][ Right ]
						+ C[ Left - 1 ] * C[ i ] * C[ Right ];
				if( ThisM < M[ Left ][ Right ] )
				{ 
					M[ Left ][ Right ] = ThisM;
					LastChange[ Left ][ Right ] = i;
				}
			}
		}
}

void 
PrintOrder( TwoDimArray LastChange, int start, int end )
{
	int k;
	if( start == end )
		printf( "A%d", start );
	else
	{
		if( start + 1 == end )
			printf( "A%dA%d", start, end );
		else
		{
			k = LastChange[ start ][ end ];
			printf("(");
			PrintOrder( LastChange, start, k );
			printf(")");
			printf("(");
			PrintOrder( LastChange, k + 1, end );
			printf(")");

		}
	}
	
}

int 
main()
{
	TwoDimArray M;
	TwoDimArray LastChange;
	const long Input[] = { 30, 35, 15, 5, 10, 20, 25 };
	OptMatrix( Input, NumMatrix, M, LastChange );
	int i, j;
	printf( "Opt Count:%d\n", M[ 1 ][ NumMatrix ] );
	PrintOrder( LastChange, 1, NumMatrix );
	printf( "\n" );

}
