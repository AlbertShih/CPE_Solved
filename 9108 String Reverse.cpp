
#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	char *str = new char[10000000];
	while( scanf("%s", str) != EOF )
	{
		int len = strlen(str);
		for( int i = len-1; i >= 0; --i )
			putchar(str[i]);
		putchar('\n');
	}
	delete[] str;
}
