
#include <iostream>

using namespace std;

int getGCD(int a, int b)
{
	while( (a%=b) && (b%=a) );
	return a+b;
}

int main()
{
	int m, n;
	
	while( scanf("%d %d", &m, &n) != EOF )
	{
		int gcd = getGCD(m, n);
		printf("%d/%d\n", m/gcd, n/gcd);
	}
}
