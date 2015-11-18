
#include <iostream>
#include <cstring>

#define MAX 120

using namespace std;

int main()
{
	char strA[MAX], strB[MAX];
	
	while( scanf("%s %s", strA, strB) != EOF )
	{
		int intA[MAX] = {0};
		int intB[MAX] = {0};
		int intC[MAX*2] = {0};
		int lenA = strlen(strA);
		int lenB = strlen(strB);
		
		for( int i = 0; i < lenA; ++i )
			intA[i] = (int)strA[lenA-1-i] - '0';
		for( int i = 0; i < lenB; ++i )
			intB[i] = (int)strB[lenB-1-i] - '0';
		
		
		for( int i = 0; i < MAX; ++i )
		{
			int carry = 0;
			for( int j = 0; j < MAX; ++j )
			{
				intC[i+j] += intA[i] * intB[j] + carry;
				carry = intC[i+j] / 10;
				intC[i+j] %= 10;
			}
		}
		
		bool hasVal = false;
		
		for( int i = 0; i < MAX*2; ++i )
		{
			if( !hasVal )
			{
				if( intC[MAX*2-1-i] > 0 )
				{
					hasVal = true;
					printf("%d", intC[MAX*2-1-i]);
				}	
			}
			else
			{
				printf("%d", intC[MAX*2-1-i]);
			}
		}
		printf("\n");
	}
	
	
	return 0;
}
