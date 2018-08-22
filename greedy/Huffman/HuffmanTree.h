#ifndef _Huffman_H
#define _Huffman_H

struct Node;
typedef struct Node HuffmanNode;
typedef struct Node * HuffmanTree;

struct Node
{
	HuffmanTree Left;
	HuffmanTree Right;
	char        Code;
	int         Freq;
};


typedef struct 
{
	char Code;
	int  Freq;
} CharNode, * CharList;

#endif
