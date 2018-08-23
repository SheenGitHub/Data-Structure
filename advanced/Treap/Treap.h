struct TreapNode;
typedef struct TreapNode *Treap;
typedef struct TreapNode *Position;
typedef int ElementType;

Treap Initialize( void );
Treap Insert( ElementType Item, Treap T );
Treap Remove( ElementType Item, Treap T );
Treap Find( ElementType Item, Treap T );
Treap FindMin( Treap T );
Treap FindMax( Treap T );
ElementType Retrieve( Position P );
