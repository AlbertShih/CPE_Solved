
#include <iostream>

using namespace std;

int summation(int **arr, int N, int i, int j)
{
	int sum = 0;
	if( i-1 >= 0   && j-1 >= 0   )
		sum += arr[i-1][j-1];
	if( i-1 >= 0                 )
		sum += arr[i-1][j  ];
	if( i-1 >= 0   && j+1 <= N-1 )
		sum += arr[i-1][j+1];
	if(               j-1 >= 0   )
		sum += arr[i  ][j-1];
	if(               j+1 <= N-1 )
		sum += arr[i  ][j+1];
	if( i+1 <= N-1 && j-1 >= 0   )
		sum += arr[i+1][j-1];
	if( i+1 <= N-1               )
		sum += arr[i+1][j  ];
	if( i+1 <= N-1 && j+1 <= N-1 )
		sum += arr[i+1][j+1];
	
	return sum;
		
}

int main()
{
	int N;
	while( scanf("%d", &N) != EOF )
	{
		int **arr = new int*[N];
		for( int i = 0; i < N; ++i )
		{
			arr[i] = new int[N];
			for( int j = 0; j < N; ++j )
				scanf("%d", &arr[i][j]);
		}
		
		for( int i = 0; i < N; ++i )
		{
			for( int j = 0; j < N; ++j)
			{
				if( j > 0 )
					printf(" ");
				printf("%d", summation(arr, N, i, j));
			}
			printf("\n");
		}
		
	}
}
