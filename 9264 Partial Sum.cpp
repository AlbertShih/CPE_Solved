
#include <iostream>

#define PARSE 100

using namespace std;

int main()
{
	int nCase;
	scanf("%d", &nCase);
	for( int l = 0; l < nCase; ++l )
	{
		int t;
		scanf("%d", &t);
		
		int *arr = new int[t];
		for( int i = 0; i < t; ++i )
			scanf("%d", &arr[i]);
		int *arrC = new int[t/PARSE];
		for( int i = 0; i < t/PARSE; ++i )
		{
			arrC[i] = 0;
			for( int j = 0; j < PARSE; ++j )
				arrC[i] += arr[i*PARSE+j];
		}
		int q;
		scanf("%d", &q);
		for( int i = 0; i < q; ++i )
		{
			int a, b;
			long long sum = 0;
			scanf("%d %d", &a, &b);
			a--;
			b;
			
			if( b - a > PARSE )
			{
				for( int j = a/PARSE+1; j < b/PARSE; ++j )
					sum += arrC[j];
				for( int j = a; j < (a/PARSE+1)*PARSE; ++j )
					sum += arr[j];
				for( int j = b/PARSE*PARSE; j < b; ++j )
					sum += arr[j];
			}
			else
			{
				for( int j = a; j < b; ++j )
					sum += arr[j];
			}
			printf("%lld\n", sum);
			
		}
		delete[] arr;
		delete[] arrC;
	}
}
