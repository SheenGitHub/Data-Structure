#include <stdio.h>
#define FatalError(msg) perror(msg)
int
main()
{
  FatalError( "Out of Space" );
  printf("Hello");
  return 0;
}
