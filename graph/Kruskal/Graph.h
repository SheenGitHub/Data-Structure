#ifndef _Graph_H
#define _Graph_H

typedef int Vertex;
typedef int WeightType;

typedef struct
{
	Vertex     V;
	Vertex     U;
	WeightType Weight;
} Edge;

typedef int Graph[][ 3 ];

#endif
