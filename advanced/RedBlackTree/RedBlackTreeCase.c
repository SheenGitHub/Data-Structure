#include <stdio.h>
#include "RedBlackTree.h"

int main()
{
	RedBlackTree T;
	RedBlackTree P;
	T = Initialize();
	int i;
	ElementType Value;


	for( i = 0; i < 16; i++ )
	{
		T = Insert( i + 1, T );
	}
	printf( "Pre Order:\n" );
	PrintPreTree( T );

}
