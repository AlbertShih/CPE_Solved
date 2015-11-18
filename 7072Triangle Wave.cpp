
#include <iostream>
/* The FUCK UVa judging needs <cstdio>
 * to use printf() and scanf()
 */
#include <cstdio>

using namespace std;

int main()
{
	int nCase;
	scanf("%d", &nCase);
	bool first = true;
	
	for( int l = 0; l < nCase; ++l )
	{
		int A, F;
		scanf("%d %d", &A, &F);
		
		for( int i = 0; i < F; ++i )
		{
			/* The FUCK UVa judging needs
			 * to ensure the format.
			 * The last output line dosen't
			 * allow '\n'
			 */
			if( first )
				first = false;
			else
				printf("\n");
				
			for( int j = 1; j < A*2; ++j )
			{
				int m = ( j < A ) ? j : A*2 - j;
				for( int k = 0; k < m; ++k )
					printf("%d", m);
				printf("\n");
		 	}
		}
	}
}
