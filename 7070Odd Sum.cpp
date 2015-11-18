
#include <iostream>
/* The FUCK UVa judging needs <cstdio>
 * to use printf() and scanf()
 */
#include <cstdio>

using namespace std;

int main()
{
	int nCase;
	scanf("%d", &nCase);
	
	for( int l = 0; l < nCase; ++l )
	{
		long long a, b;
		scanf("%lld %lld", &a, &b);
		if( a % 2 == 0 )
			a++;
		if( b % 2 == 0 )
			b--;
		long long result = (( b - a ) / 2 + 1 ) * ( b + a ) / 2;
		printf("Case %d: %lld\n", l+1, result);
	}
}
