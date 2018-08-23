
work : TreapCase.o Treap.o
	cc -o work TreapCase.o Treap.o
TreapCase.o : TreapCase.c Treap.h
	cc -c TreapCase.c
Treap.o : Treap.c Treap.h
	cc -c Treap.c
clean:
	rm *.o work
