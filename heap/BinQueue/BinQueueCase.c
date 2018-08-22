#include <stdio.h>
#include "BinQueue.h"
int main()
{
	int i;
	int Element;
	BinQueue H1 = NULL, H2 = NULL;

	H1 = Insert( 16, H1 );
	H1 = Insert( 18, H1 );
	H1 = Insert( 12, H1 );
	H1 = Insert( 21, H1 );
	H1 = Insert( 24, H1 );
	H1 = Insert( 65, H1 );

	H2 = Insert( 13, H2 );
	H2 = Insert( 14, H2 );
	H2 = Insert( 26, H2 );
	H2 = Insert( 23, H2 );
	H2 = Insert( 51, H2 );
	H2 = Insert( 24, H2 );
	H2 = Insert( 65, H2 );

	H1 = Merge( H1, H2 );
	for( i = 0; i < 13; i++ )
	{
		Element = DeleteMin( H1 );
		printf( "%d\n", Element );
	}
}
