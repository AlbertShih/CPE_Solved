
#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	
	int nCase;
	scanf("%d", &nCase);
	
	for( int l = 0; l < nCase; ++l )
	{
		int length;
		scanf("%d", &length);
		
		int A[length], B[length], C[length];
		for( int i = 0; i < length; ++i )
			scanf("%d", &A[i]);
		for( int i = 0; i < length; ++i )
			scanf("%d", &B[i]);
		
		char O[1020];
		scanf("%s", O);
		
		int bOffset, cOffset;
		for( int i = 1; i < strlen(O); ++i )
		{
			if( O[i] == '1' )
			{
				bOffset = i - 1;
				break;
			}
		}
		cOffset = strlen(O) - 3 - bOffset;
		
		for( int i = 0; i < length; ++i )
		{
			C[ (i + cOffset) % length ] = A[i] + B[ (i + bOffset) % length ]; 
		}
		for( int i = 0; i < length; ++i )
		{
			if( i != 0 )
				printf(" ");
			printf("%d", C[i]);
		}
		
		printf("\n");
	}
	
	
	
	return 0;
}
