#ifndef _BinQueue_H
struct BinNode;
struct Collection;
typedef struct BinNode *Position;
typedef struct BinNode *BinTree;
typedef struct Collection *BinQueue;

BinTree CombineTrees( BinTree T1, BinTree T2 );
BinQueue Merge( BinQueue H1, BinQueue H2 );
ElementType DeleteMin( BinQueue H );
BinQueue Initialize( void );
BinQueue Insert( ElementType X, BinQueue H );
int IsEmpty( BinQueue );

#endif
