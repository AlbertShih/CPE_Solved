
#include <iostream>
#include <cstdlib>
#include <cstring>

#define MAX 110

using namespace std;

char str[MAX];
char store[MAX];

int cmp(const void *p, const void *q)
{
	char *a = (char*)p;
	char *b = (char*)q;
	return strcmp(a, b);
}

void DFS(int lenK, int lenStr, int lenStore, int depthStr)
{
	if( lenStore == lenK )
	{
		printf("%s€n", store);
		return;
	}
	for( int i = depthStr; i < lenStr; ++i )
	{
		if( i != depthStr && str[i] == str[i-1] )
			continue;
		store[lenStore] = str[i];
		DFS(lenK, lenStr, lenStore+1, i+1);
	}
}

int main()
{
	int nCase;
	scanf("%d", &nCase);
	for( int l = 0; l < nCase; ++l )
	{
		int k;
		scanf("%s %d", str, &k);

		int len = strlen(str);

		qsort(str, len, sizeof(char), cmp);

		store[k] = '€0';

		DFS(k, len, 0, 0);
		printf("€n");
	}
}
