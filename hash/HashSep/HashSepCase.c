#include <stdio.h>
#include "HashSep.h"
int main(){
	int TableSize = 14;
	HashTable hashTable;
	Position pos;

	hashTable = InitializeTable( TableSize );
	Insert( 89, hashTable );
	Insert( 18, hashTable );
	Insert( 49, hashTable );
	Insert( 66, hashTable );
	Insert( 58, hashTable );
	Insert( 69, hashTable );
	
	pos = Find( 49, hashTable );
	if( pos )
	{
		printf( "Find %d\n", pos->Element );
	}

	pos = Find( 66, hashTable );
	if( pos )
	{
		printf( "Find %d\n", pos->Element );
	}
}
