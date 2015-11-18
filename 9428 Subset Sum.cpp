
#include <iostream>

#define MAX 20

using namespace std;

int tag[MAX];
int arr[MAX];
int minimun;

int abs(int x)
{
	return ( x >= 0 ) ? x : -x;
}

void DFS(int total, int depth)
{
	if( depth > total )
		return;
	int count1 = 0;
	int count2 = 0;
	for( int i = 0; i < total; ++i )
	{
		if( tag[i] )
			count1 += arr[i];
		else
			count2 += arr[i];
	}
	int result = abs(count1-count2);
	if( result < minimun )
		minimun = result;
	
	tag[depth] = 0;
	DFS(total, depth+1);
	tag[depth] = 1;
	DFS(total, depth+1);
}

int main()
{
	int N;
	while( true )
	{
		scanf("%d", &N);
		if( N == 0 )
			break;
		
		int count = 0;
		for( int i = 0; i < N; ++i )
		{
			scanf("%d", &arr[i]);
			tag[i] = 0;
			count += arr[i];
		}
		minimun = abs(count);
		DFS(N, 0);
		
		printf("%d\n", minimun);
	}
}
