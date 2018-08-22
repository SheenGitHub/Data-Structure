#include <stdio.h>
#include <stdlib.h>
#include "BinHeap.h"


int top = 0;
int stack[7] = { -1, -1, -1, -1, -1, -1, -1 };

void 
HuffmanCode( HuffmanTree Tree )
{
	int i;
	if( Tree )
	{
		if( Tree->Left == NULL && Tree->Right == NULL )
		{
			printf( "%c:", Tree->Code );
			for( i = 0; i < top; i++ )
				printf( "%d", stack[i] );
			printf("\n");
		}

		if( Tree->Left )
		{
			stack[ top++ ] = 1;
			HuffmanCode( Tree->Left );
			stack[ top-- ] = -1;
		}

		if( Tree->Right )
		{
			stack[ top++ ] = 0;
			HuffmanCode( Tree->Right );
			stack[ top-- ] = -1;
		}

	}
}

int 
main()
{
	CharNode 
	Chars[] = 
		{
			{},
			{ 'a', 10 },
			{ 'e', 15 },
			{ 'i', 12 },
			{ 's', 3 },
			{ 't', 4 },
			{ ' ', 13 },
			{ '\n', 1 }
		};
	PriorityQueue H;
	H = InitializeHeap( 7 );
	ReadNodeIntoHeapArray( Chars, H, 7 );
	BuildHeap( H );

	HuffmanTree T1, T2, Tree;

	while( !IsOnly( H ) )
	{
		T1 = DeleteMin( H );
		T2 = DeleteMin( H );
		printf( "T1: %c %d, T2: %c %d \n",T1->Code, T1->Freq, T2->Code, T2->Freq );
		Tree = malloc( sizeof( HuffmanNode ) );
		if( Tree == NULL )
			perror( "Out of Space" );
		if( T2->Freq < T1->Freq )
		{
			Tree->Left  = T2; Tree->Right = T1;
		}
		else
		{
			Tree->Left  = T1; Tree->Right = T2;
		}
		Tree->Freq  = T1->Freq + T2->Freq;
		Tree->Code  = 'x';
		Insert( Tree, H );
	}
	HuffmanCode( Tree );
}
