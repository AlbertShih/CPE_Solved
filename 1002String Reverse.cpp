
#include <iostream>
#include <cstring>

#define MAX 1000010

using namespace std;

int main()
{
	char str[MAX];
	char strX[MAX];
	
	while( scanf("%s",str) != EOF )
	{
		int len = strlen(str);
		for( int i = 0; i < len; ++i )
			strX[i] = str[len-1-i];
		strX[len] = '\0';
		printf("%s\n", strX);
	}
	
	return 0;
}

