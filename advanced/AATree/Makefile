
work : AATreeCase.o AATree.o
	cc -o work AATreeCase.o AATree.o
AATreeCase.o : AATreeCase.c AATree.h
	cc -c AATreeCase.c
AATree.o : AATree.c AATree.h
	cc -c AATree.c
clean:
	rm *.o work
