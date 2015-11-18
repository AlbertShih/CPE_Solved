
#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	char strA[1010], strB[1010];
	while( scanf("%s %s", strA, strB) != EOF )
	{
		int ptrA = strlen(strA)-1;
		int ptrB = strlen(strB)-1;
		int count = 0;
		int carry = 0;
		while( ptrA >= 0 && ptrB >= 0 )
		{
			int sum = carry;
			sum += strA[ptrA] - '0';
			sum += strB[ptrB] - '0';
			if( sum / 10 )
				count++;
			carry = sum / 10;
			ptrA--;
			ptrB--;
		}
		while( ptrA >= 0 )
		{
			int sum = carry;
			sum += strA[ptrA] - '0';
			if( sum / 10 )
				count++;
			carry = sum / 10;
			ptrA--;
		}
		while( ptrB >= 0 )
		{
			int sum = carry;
			sum += strB[ptrB] - '0';
			if( sum / 10 )
				count++;
			carry = sum / 10;
			ptrB--;
		}
		printf("%d\n", count);
	}
}
