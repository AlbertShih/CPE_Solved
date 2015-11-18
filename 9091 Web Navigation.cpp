
#include <iostream>
#include <cstring>
#include <stack>

#define CMD_LEN 10
#define URL_LEN 110

using namespace std;

typedef struct URL
{
	char url[URL_LEN];
}	URL;

int main()
{
	//freopen("9091_input.txt", "r", stdin);
	
	char cmd[CMD_LEN];
	stack<URL> forward, backward;
	URL current;
	strcpy(current.url, "http://www.acm.org/");
	
	while( scanf("%s", cmd) != EOF )
	{
		if( !strcmp(cmd, "VISIT") )
		{
			backward.push(current);
			while( !forward.empty() )
				forward.pop();
			scanf("%s", current.url);
			printf("%s\n", current.url);
		}
		else if( !strcmp(cmd, "BACK") )
		{
			if( backward.empty() )
			{
				printf("Ignored\n");
			}
			else
			{
				forward.push(current);
				strcpy(current.url, backward.top().url);
				printf("%s\n", current.url);
				backward.pop();
			}
		}
		else if( !strcmp(cmd, "FORWARD") )
		{
			if( forward.empty() )
			{
				printf("Ignored\n");
			}
			else
			{
				backward.push(current);
				strcpy(current.url, forward.top().url);
				printf("%s\n", current.url);
				forward.pop();
			}
		}
	}
}
