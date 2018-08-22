#include <stdio.h>
#include "LeftHeap.h"
int main()
{
	PriorityQueue H1 = NULL;
	PriorityQueue H2 = NULL;
	PriorityQueue H3 = NULL;

	Insert( 3, H1 );
	Insert( 10, H1 );
	Insert( 8, H1 );
	Insert( 21, H1 );
	Insert( 14, H1 );
	Insert( 17, H1 );
	Insert( 23, H1 );
	Insert( 26, H1 );
	
	Insert( 6, H2 );
	Insert( 12, H2 );
	Insert( 7, H2 );
	Insert( 18, H2 );
	Insert( 24, H2 );
	Insert( 37, H2 );
	Insert( 18, H2 );
	Insert( 33, H2 );
	
	H3 = Merge( H2, H1 );
	
	PriorityQueue H4;
	int i;
	for( i = 0; i < 16; i++ )
	{
		PrintElement( H3 );
		DeleteMin( H3 );
	}

}
