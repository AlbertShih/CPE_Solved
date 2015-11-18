
#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

int cmp(const void *p, const void *q)
{
	char *a = (char*)p;
	char *b = (char*)q;
	return strcmp(a, b);
}

int main()
{
	while( true )
	{
		int n;
		scanf("%d", &n);
		if( n == 0 )
			break;
		
		char name[1010][52];
		for( int i = 0; i < n; ++i )
		{
			scanf("%s", name[i]);
		}
		
		qsort(name, n, sizeof(name[0]), cmp);
		
		for( int i = 0; i < n; ++i )
		{
			printf("%s\n", name[i]);
		}
			
		putchar('\n');
		
	}
}
