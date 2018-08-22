#include "Hash.h"
Index Hash( int Key, int TableSize )
{
	return Key % TableSize;
}

int IsPrime( int num )
{
	int i;

	if( num == 2 || num == 3 )
	{
		return 0;
	}
	if( num % 6 != 1 && num % 6 != 5 )
	{
		return 0;
	}

	for( i = 5; i * i <= num; i += 6 )
	{
		if( num % i == 0 || num % ( i + 2 ) == 0 )
		{
			return 0;
		}
	}

	return 1;
}

int NextPrime( num )
{
	int state = IsPrime( num );

	while( !state )
	{
		state = IsPrime( ++num );
	}

	return num;
}
