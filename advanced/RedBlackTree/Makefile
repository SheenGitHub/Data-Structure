
work : RedBlackTreeCase.o RedBlackTree.o
	cc -o work RedBlackTreeCase.o RedBlackTree.o
RedBlackTreeCase.o : RedBlackTreeCase.c RedBlackTree.h
	cc -c RedBlackTreeCase.c
RedBlackTree.o : RedBlackTree.c RedBlackTree.h
	cc -c RedBlackTree.c
clean:
	rm *.o work
