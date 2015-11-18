
#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	char str[100010];
	while( scanf("%s", str) != EOF )
	{
		bool palindrome = true;
		int len = strlen(str);
		bool odd = len % 2;
		
		for( int i = 0; i < len/2 + odd; ++i )
			if( str[len/2-i-!odd] != str[len/2+i] )
			{
				palindrome = false;
				break;
			}
		
		if( palindrome )
			printf("Yes\n");
		else
			printf("No\n");
		
	}
}
