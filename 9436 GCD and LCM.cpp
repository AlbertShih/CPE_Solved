
#include <iostream>

using namespace std;

long long getGCD(long long a, long long b)
{
	while((a%=b) && (b%=a));
	return a+b;
}

int main()
{
	int nCase;
	scanf("%d", &nCase);
	
	for( int l = 0; l < nCase; ++l )
	{
		long long  x, y, z;
		scanf("%lld %lld %lld", &x, &y, &z);
		long long gcd = getGCD(x,getGCD(y,z));
		long long lcm = 1;
		lcm *= ( x / getGCD(x, y) );
		lcm *= ( y / getGCD(y, z) );
		lcm *= ( z / getGCD(z, x) );
		lcm *= gcd;
		printf("%lld %lld\n", gcd, lcm);
	}
}
