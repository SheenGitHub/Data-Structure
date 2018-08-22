work : SplayTreeCase.o SplayTree.o
	cc -o work SplayTreeCase.o SplayTree.o
SplayTreeCase.o : SplayTreeCase.c SplayTree.h
	cc -c SplayTreeCase.c
SplayTree.o : SplayTree.c SplayTree.h
	cc -c SplayTree.c
clean:
	rm *.o work
