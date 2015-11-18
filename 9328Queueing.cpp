
#include <iostream>
#include <cstring>
#include <queue>

#define NAME_LEN 24

using namespace std;

typedef struct Name
{
	char name[NAME_LEN];
}	Name;

int main()
{
	char cmd[20];
	queue<Name> q;
	while( scanf("%s", cmd) != EOF )
	{
		if( !strcmp(cmd, "Push") )
		{
			Name name;
			scanf("%s", name.name);
			q.push(name);
		}
		else if( !strcmp(cmd, "Pop") )
		{
			if( !q.empty() )
				q.pop();
		}
		else
		{
			if( q.empty() )
				printf("empty\n");
			else
				printf("%s\n", q.front().name);
		}
	}
}
