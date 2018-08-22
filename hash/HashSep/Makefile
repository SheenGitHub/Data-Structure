work : HashSepCase.o HashSep.o Hash.o
	cc -o work HashSepCase.o HashSep.o Hash.o
HashSepCase.o : HashSepCase.c HashSep.h
	cc -D ElementType=int -c HashSepCase.c
HashSep.o : HashSep.c HashSep.h Hash.h 
	cc -D ElementType=int -D MinTableSize=10 -c HashSep.c
Hash.o : Hash.c Hash.h
	cc -c Hash.c
clean :
	rm *.o work

