
#include <iostream>

using namespace std;

int power(int B, int P, int M)
{
	B = B % M;
	if( P == 0 )
		return 1;
	else if( P == 1 )
		return B;
	else
		return power(B*B, P/2, M) * power(B, P%2, M) % M;
}

int main()
{
	int B, P, M;
	
	while( scanf("%d %d %d", &B, &P, &M) != EOF )
	{
		int R = power(B, P, M);
		printf("%d\n", R);
	}
	
}
