struct AANode;
typedef struct AANode *AATree;
typedef struct AANode *Position;
typedef int ElementType;

AATree Initialize( void );
AATree Insert( ElementType Item, AATree T );
AATree Remove( ElementType Item, AATree T );
AATree Find( ElementType Item, AATree T );
AATree FindMin( AATree T );
AATree FindMax( AATree T );
ElementType Retrieve( Position P );
