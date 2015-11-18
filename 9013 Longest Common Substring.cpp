
#include <iostream>
#include <cstring>

#define STR_LEN 1010

using namespace std;

int main()
{
	int nCase;
	scanf("%d", &nCase);
	
	for( int l = 0; l < nCase; ++l )
	{
		char strA[STR_LEN], strB[STR_LEN];
		scanf("%s %s", strA, strB);
		
		int lenA = strlen(strA);
		int lenB = strlen(strB);
		int **arr = new int*[lenA+1];
		for( int i = 0; i < lenA+1; ++i )
		{
			arr[i] = new int[lenB+1];
			for( int j = 0; j < lenB+1; ++j )
				arr[i][j] = 0;
		}
		
		for( int i = 0; i < lenA; ++i )
		{
			for( int j = 0; j < lenB; ++j )
			{
				if( strA[i] == strB[j] )
				{
					arr[i+1][j+1] = arr[i][j] + 1;
				}
			}
		}
		int max = 0;
		for( int i = 0; i < lenA+1; ++i)
			for( int j = 0; j < lenB+1; ++j )
			{
				if( arr[i][j] > max )
					max = arr[i][j];
			}
		printf("%d\n", max);
		
		for( int i = 0; i < lenA+1; ++i )
			delete[] arr[i];
		delete[] arr;
	}
}
