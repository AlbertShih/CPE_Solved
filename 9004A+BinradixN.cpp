
#include <iostream>
#include <cstring>

#define MAX 110

using namespace std;

int main()
{
	int N;
	char A[MAX], B[MAX], C[MAX];
	while( scanf("%d %s %s", &N, A, B) != EOF )
	{
		// remove '\n'
		getchar();
		
		memset(C, 0, MAX);
		
		int lenA = strlen(A);
		int lenB = strlen(B);
		int carry = 0;
		int i = lenA - 1;
		int j = lenB - 1;
		for( int k = MAX-1; k >= 0; --k )
		{
			int sum = carry;
			if( i >= 0 )
			{
			 	if( A[i] >= 'A' )
					sum += A[i] - 'A' + 10;
				else
					sum += A[i] - '0';
			}
			
			if( j >= 0 )
			{
				if( B[j] >= 'A' )
					sum += B[j] - 'A' + 10;
				else
					sum += B[j] - '0';
			}
			
			carry = sum / N;
			sum %= N;
			if( sum >= 10 )
				C[k] = sum + 'A' - 10;
			else
				C[k] = sum + '0';
			
			i--;
			j--;
		}
		
		bool first = true;
		for( int k = 0; k < MAX; ++k )
		{
			if( first && C[k] == '0' )
				continue;
			else
				first = false;
			printf("%c", C[k]);
		}
		printf("\n");	
	}
}
