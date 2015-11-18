
#include <iostream>
#include <cstring>

#define MAX 210

using namespace std;

int main()
{
	int N, M;
	while( scanf("%d %d", &N, &M) != EOF )
	{
		getchar();
		char **str = new char*[N];
		int *len = new int[N];
		for( int i = 0; i < N; ++i )
		{
			str[i] = new char[MAX];
			fgets(str[i], MAX, stdin);
			len[i] = strlen(str[i]);
			/* remove str[i] 's '\n' */
			str[i][len[i]-1] = '\0';
			for( int j = 0; j < len[i]; j++ )
				if( str[i][j] >= 'A' && str[i][j] <= 'Z' )
					str[i][j] = str[i][j] - 'A' + 'a';
		}
		
		for( int i = 0; i < M; ++i )
		{
			/* case sensitive */
			char findCS[MAX];
			/* ignore case */
			char findIC[MAX];
			
			scanf("%s", findCS);
			strcpy(findIC, findCS);
			int lenF = strlen(findCS);
			for( int j = 0; j < lenF; ++j )
				if( findIC[j] >= 'A' && findIC[j] <= 'Z' )
					findIC[j] = findIC[j] - 'A' + 'a';
			
			
			int cnt = 0;
			for( int j = 0; j < N; ++j )
				for( int k = 0; k < len[j]-lenF; ++k )
				{
					bool same = true;
					for( int l = 0; l < lenF; ++l )
					{
						if( str[j][k+l] != findIC[l] )
						{
							same = false;
							break;
						}
					}
					if( same )
						cnt++;
				}
			printf("%s:%d\n", findCS, cnt);
		}
		printf("\n");
		
		for( int i = 0; i < N; ++i )
			delete[] str[i];
		delete[] str;
		delete[] len;
	}
}
