work : AvlTreeCase.o AvlTree.o
	cc -o work AvlTreeCase.o AvlTree.o
AvlTreeCase.o : AvlTreeCase.c AvlTree.h
	cc -D ElementType=int -c AvlTreeCase.c
AvlTree.o : AvlTree.c AvlTree.h
	cc -D ElementType=int -c AvlTree.c
clean : 
	rm work AvlTreeCase.o AvlTree.o
