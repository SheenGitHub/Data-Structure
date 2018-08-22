#ifndef _BinHeap_H
#include "Graph.h"
#define _BinHeap_H

struct HeapStruct;

typedef Edge HeapElemType;
typedef struct HeapStruct *PriorityQueue;

PriorityQueue InitializeHeap( int MaxElements );
void Destroy( PriorityQueue H );
void MakeEmpty( PriorityQueue H );
void Insert( HeapElemType X, PriorityQueue H );
HeapElemType DeleteMin( PriorityQueue H );
HeapElemType FindMin( PriorityQueue H );
int IsEmpty( PriorityQueue H );
int IsFull( PriorityQueue H );
void PrintHeap( PriorityQueue H );
void BuildHeap( PriorityQueue H );
void ReadGraphIntoHeapArray( Graph G, PriorityQueue H, int NumEdges );

#endif

