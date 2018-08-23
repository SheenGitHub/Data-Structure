typedef int ItemType[2];
struct KdNode;
typedef struct KdNode * KdTree;
KdTree Insert( ItemType Item, KdTree T );
void PrintRange( ItemType Low, ItemType High, KdTree );
