#ifndef _BinHeap_H
#include "HuffmanTree.h"
#define _BinHeap_H

struct HeapStruct;

typedef HuffmanTree HeapElemType;
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
void ReadNodeIntoHeapArray( CharList Nodes, PriorityQueue H, int CharNum );
int IsOnly( PriorityQueue H );
#endif

