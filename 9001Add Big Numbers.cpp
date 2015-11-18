
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
		int intC[MAX] = {0};
		bool hasSignA = ( strA[0] == '-' );
		bool hasSignB = ( strB[0] == '-' );
		int lenA = !hasSignA ? strlen(strA) : ( strlen(strA)-1 );
		int lenB = !hasSignB ? strlen(strB) : ( strlen(strB)-1 );
		int minLen = lenA < lenB ? lenA : lenB;
		
		for( int i = 0; i < lenA; ++i )
		{
			intA[i] = (int)strA[lenA+hasSignA-1-i] - '0';
			if( hasSignA )
				intA[i] *= -1;
		}
		for( int i = 0; i < lenB; ++i )
		{
			intB[i] = (int)strB[lenB+hasSignB-1-i] - '0';
			if( hasSignB )
				intB[i] *= -1;
		}
		
		int carry = 0;
		for( int i = 0; i < MAX; ++i )
		{
			intC[i] = intA[i] + intB[i] + carry;
			carry = intC[i] / 10;
			intC[i] %= 10;
		}
		bool signOfMSB;
		for( int i = 0; i < MAX; ++i )
		{
			if( intC[MAX-1-i] != 0)
			{
				signOfMSB = intC[MAX-1-i] > 0 ? false : true;
				break;
			}
		}
		
		if( !signOfMSB )
		{
			for( int i = 0; i < MAX-1; ++i )
			{
				if( intC[i] < 0 )
				{
					intC[i] += 10;
					intC[i+1]--;
				}
			}
		}
		else
		{
			for( int i = 0; i < MAX-1; ++i )
			{
				if( intC[i] > 0 )
				{
					intC[i] -= 10;
					intC[i+1]++;
				}
			}
		}
		
		
		bool hasVal = false;
		bool zero = true;
		for( int i = 0; i < MAX; ++i )
		{
			if( !hasVal )
			{
				if( intC[MAX-1-i] != 0 )
				{
					zero = false;
					hasVal = true;
					if( !signOfMSB )
						printf("%d", intC[MAX-1-i]);
					else
					{
						printf("-%d", -intC[MAX-1-i]);
					}
				}
			}
			else
			{
				if( !signOfMSB )
					printf("%d", intC[MAX-1-i]);
				else
					printf("%d", -intC[MAX-1-i]);
			}
		}
		if( zero )
			printf("0");
		
		printf("\n");
	
	}
	
	
	return 0;
}
