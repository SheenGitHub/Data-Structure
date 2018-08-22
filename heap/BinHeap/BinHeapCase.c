#include <stdio.h>
#include "BinHeap.h"
int main()
{
	int i, MaxElements = 16;
	PriorityQueue Heap = Initialize( MaxElements );
	for( i = MaxElements; i > 0; i-- )
		Insert( i, Heap );

	DeleteMin( Heap );
	DeleteMin( Heap );

	PrintHeap( Heap );
}
