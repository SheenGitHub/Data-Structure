#include <limits.h>
#define NumVertex (7)
#ifndef _AdjTable_H

typedef int Vertex;

#define False (0)
#define True (1)
#define Infinity (INT_MAX)
#define NotAVertex (-1)

struct TableEntry;
struct AdjVNode;

typedef struct AdjVNode *PtrToAdjVNode;
typedef struct AdjVNode *List;
typedef int Graph[ NumVertex ][ NumVertex ];

struct AdjVNode
{
	Vertex        AdjV;
	PtrToAdjVNode Next;
};

struct TableEntry
{
	List     Header;
	int      Visited;
	Vertex   Low;
	int      Number;
	Vertex   Parent;
};

typedef struct TableEntry Table[ NumVertex ];

#endif
