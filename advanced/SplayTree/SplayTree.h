#ifndef _Splay_H
struct SplayNode;
typedef struct SplayNode *SplayTree;

typedef int ElementType;

#define FakeValue (99999)

SplayTree MakeEmpty( SplayTree );
SplayTree Find( ElementType X, SplayTree T );
SplayTree FindMin( SplayTree T );
SplayTree FindMax( SplayTree T );
SplayTree Initialize( void );
SplayTree Insert( ElementType X, SplayTree T );
SplayTree Remove( ElementType X, SplayTree T );
ElementType Retrieve( SplayTree T ); /* Gets root item */

#endif
