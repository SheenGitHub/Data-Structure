#include <stdio.h>
#include "Sort.h"
void PrintArray( ElementType A[], int N )
{
	int i;
	for( i = 0; i < N; i++ )
	{
		printf( "%d ", A[ i ] );
	}
	printf( "\n" );
}

int main()
{
	int arr[] = { 1, 9, 2, 10, 3, 11, 4, 12, 5, 13, 6, 14, 7, 15, 8, 16 };

	//InsertionSort( arr, 16 );
	//ShellSort( arr, 16 );
	//HeapSort( arr, 16 );
	//MergeSort( arr, 16 );
	//QuickSort( arr, 16 );
	int k = 13;
	int v = QuickSelect( arr, k, 16 );
	printf( " Pos %d is %d\n", k, v );
	//PrintArray( arr, 16 );
}

