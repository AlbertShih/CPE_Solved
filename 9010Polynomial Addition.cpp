
#include <iostream>

#define MAX 1010

using namespace std;

int main()
{
	int nCase;
	scanf("%d", &nCase);
	
	for( int l = 0; l < nCase; ++l )
	{
		int arrA[MAX] = {0};
		int arrB[MAX] = {0};
		int lenA, lenB;
		scanf("%d %d", &lenA, &lenB);
		
		int lenX = (lenA > lenB) ? lenA : lenB;
		
		for( int i = lenA; i >= 0; --i )
			scanf("%d", &arrA[i]);
		for( int i = lenB; i >= 0; --i )
			scanf("%d", &arrB[i]);
		for( int i = 0; i < 1010; ++i )
			arrA[i] += arrB[i];
		
		bool first = true;
		for( int i = lenX; i >=0; --i )
		{
			if( first && arrA[i] == 0 )
				continue;
			else if( first && arrA[i] != 0 )
			{
				printf("%d", arrA[i]);
				first = false;
				continue;
			}
			printf(" %d", arrA[i]);
		}
		printf("\n");
	}
}
