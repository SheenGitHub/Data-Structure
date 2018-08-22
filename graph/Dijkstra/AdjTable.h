#include <limits.h>
#ifndef _AdjTable_H

typedef int Vertex;
typedef int WeightType;
typedef int DistType;

#define False (0)
#define True (1)
#define Infinity (INT_MAX)
#define NotAVertex (-1)

struct TableEntry;
struct AdjVNode;

typedef struct AdjVNode *PtrToAdjVNode;
typedef struct AdjVNode *List;

struct TableEntry
{
	List     Header;
	int      Known;
	DistType Dist;
	Vertex   Path;
};

typedef int Graph[ NumVertex ][ NumVertex ];
typedef struct TableEntry Table[ NumVertex ];


#endif
