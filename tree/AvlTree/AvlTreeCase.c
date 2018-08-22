#include <stdio.h>
#include "AvlTree.h"

void preOrder( AvlTree T )
{
	if( T != NULL )
	{
		printf( "Element:%d\n", T->Element );
		preOrder( T->Left );
		preOrder( T->Right );
	}
}

void InOrder( AvlTree T )
{
	if( T != NULL )
	{
		InOrder( T->Left );
		printf( "Element:%d\n", T->Element );
		InOrder( T->Right );
	}
}

int main()
{
  AvlTree T = NULL;
  Position min, max;
  int i;
  for( i = 1; i < 8; i++ )
  {
    T = Insert( i, T );
  }

  max = FindMax( T );
  min = FindMin( T );
  printf( "max %d\n", max->Element );
  printf( "min %d\n", min->Element );

  printf( "preOrder:\n" );
  preOrder( T );

  printf( "inOrder:\n" );
  InOrder( T );
}
