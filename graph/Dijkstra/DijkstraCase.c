#include <stdio.h>
#include "Dijkstra.h"

int 
main()
{
	Graph 
	Input = 
	{
		0, 2, 0, 1, 0, 0, 0,
		0, 0, 0, 3,10, 0, 0,
		4, 0, 0, 0, 0, 5, 0,
		0, 0, 2, 0, 2, 8, 4,
		0, 0, 0, 0, 0, 0, 6,
		0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 1, 0
	};
	Table T;
	int i;

	InitTable( 0, Input, T);
	Dijkstra( T );
	for( i = 0; i < NumVertex; i++ )
	{
		printf( "Path %d (Weight %d):", i, PathWeight( i, T ) );
		PrintPath( i, T );
		printf( "\n" );
	}
}
