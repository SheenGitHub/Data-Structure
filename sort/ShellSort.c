#include "Sort.h"
void 
ShellSort( ElementType A[], int N )
{
	int i, j, Increment;
	for( Increment = N / 2; Increment > 0; Increment /= 2 )
	{
		ElementType Tmp;
		for( i = Increment; i < N; i++ )
		{
			Tmp = A[ i ];
			for( j = i; j > 0 && A[ j - Increment ] > Tmp; j -= Increment )
			{
				A[ j ]	= A[ j - Increment ];
			}
			A[ j ] = Tmp;
			
		}
	}
}

