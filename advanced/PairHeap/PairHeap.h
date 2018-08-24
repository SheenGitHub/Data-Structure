struct PairNode;
typedef struct PairNode *PairHeap;
typedef struct PairNode *Position;

typedef int ElementType;

Position CompareAndLink( Position First, Position Second );
PairHeap Insert( ElementType Item, PairHeap H, Position *Loc );
PairHeap DecreaseKey( Position P, ElementType Delta, PairHeap H );
PairHeap DeleteMin( ElementType *MinItem, PairHeap H );
PairHeap CombineSiblings( Position FirstSibling );
ElementType Retrieve( Position P );
