
#include <iostream>
#include <cstring>

#define STR_LEN 22

using namespace std;

int main()
{
	//freopen("9039_input.txt", "r", stdin);
	int nCase;
	scanf("%d", &nCase);
	
	for( int l = 0; l < nCase; ++l )
	{
		int nString;
		scanf("%d", &nString);
		
		char str[STR_LEN];
		
		for( int i = 0; i < nString; ++i )
		{
			scanf("%s", str);
			int len = 20 - strlen(str);
			for( int j = 0; j < len; ++j )
				putchar(' ');
			printf("%s", str);
			if( (i != 0 && i % 4 == 3) || i == nString-1 )
				printf("\n");
		}
		printf("\n");
	}
}
