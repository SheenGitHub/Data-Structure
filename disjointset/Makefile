work : DisjSetCase.o DisjSet.o
	cc -o work DisjSetCase.o DisjSet.o
work1 : DisjSetCase.o DisjSetUnionByHeight.o
	cc -o work1 DisjSetCase.o DisjSetUnionByHeight.o
work2 : DisjSetCase.o DisjSetCompression.o
	cc -o work2 DisjSetCase.o DisjSetCompression.o
DisjSetCase.o : DisjSetCase.c DisjSet.h
	cc -D NumSets=8 -c DisjSetCase.c
DisjSet.o : DisjSet.c DisjSet.h
	cc -D NumSets=8 -c DisjSet.c
DisjSetUnionByHeight.o : DisjSetUnionByHeight.c DisjSet.h
	cc -D NumSets=8 -c DisjSetUnionByHeight.c
DisjSetCompression.o : DisjSetCompression.c DisjSet.h
	cc -D NumSets=8 -c DisjSetCompression.c
clean:
	rm *.o work*
