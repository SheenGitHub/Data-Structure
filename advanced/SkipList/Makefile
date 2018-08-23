
work : SkipListCase.o SkipList.o
	cc -o work SkipListCase.o SkipList.o
SkipListCase.o : SkipListCase.c SkipList.h
	cc -c SkipListCase.c
SkipList.o : SkipList.c SkipList.h
	cc -c SkipList.c
clean:
	rm *.o work
