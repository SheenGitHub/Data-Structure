work : Huffman.o BinHeap.o
	cc -o work Huffman.o BinHeap.o
Huffman.o : Huffman.c BinHeap.h
	cc -c Huffman.c
BinHeap.o : BinHeap.c BinHeap.h HuffmanTree.h
	cc -D MinPQSize=5 -c BinHeap.c
clean:
	rm *.o work
