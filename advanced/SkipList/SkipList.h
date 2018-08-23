struct SkipNode;
typedef struct SkipNode * SkipList;
typedef struct SkipNode * Position;

typedef int ElementType;

SkipList Initialize( void );
Position Find( ElementType Item, SkipList L );
SkipList Insert( ElementType Item, SkipList L );
ElementType Retrieve( Position P );


