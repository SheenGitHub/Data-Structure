work : KdTreeCase.o KdTree.o
	cc -o work KdTreeCase.o KdTree.o
KdTreeCase.o : KdTreeCase.c KdTree.h
	cc -c KdTreeCase.c
KdTree.o : KdTree.c KdTree.h
	cc -c KdTree.c
clean:
	rm *.o work
