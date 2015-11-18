
#include <iostream>
#include <cstring>

#define MAX 1000010

using namespace std;

int find(unsigned long long n, int *store)
{
	if( n == 1 )
		return 0;
	if( n < MAX && store[n] > 0 )
	{
		return store[n];
	}
	unsigned long long k;
	if( n % 2 )
		k = n * 3 + 1;
	else
		k = n / 2;
	int cnt = find(k, store);
	cnt++;
	if( n < MAX )
		store[n] = cnt;
	return cnt;
}

int main()
{
	unsigned long long n;
	int *store = new int[MAX];
	memset(store, 0, sizeof(int)*MAX);
	
	while( scanf("%lld", &n) != EOF )
	{
		
		printf("%d\n", find(n,store));
	}
	
	delete[] store;
}
