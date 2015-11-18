
#include <iostream>
/* The FUCK UVa judging needs <cstdio>
 * to use printf() and scanf()
 */
#include <cstdio>

using namespace std;

int main()
{
	int N;
	while( scanf("%d", &N) != EOF )
	{
		if( N == 0 )
			break;
		
		int count = 0;
		for( int i = 1; i <= N; ++i )
			count += (N-i+1)*(N-i+1);
		printf("%d\n", count);
	}
}
