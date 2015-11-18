
#include <iostream>
#include <cstdlib>

using namespace std;

typedef struct Pair
{
	int point[2];
}	Pair;

int cmp(const void *p, const void *q)
{
	Pair a = *(Pair*)p;
	Pair b = *(Pair*)q;
	return a.point[0] - b.point[0];
}

int main()
{
	int N;
	while( scanf("%d", &N) != EOF )
	{
		if( N == 0 )
			break;
		
		Pair *pair = new Pair[N];
		for( int i = 0; i < N; ++i )
		{
			scanf("%d %d", &pair[i].point[0], &pair[i].point[1]);
		}
		qsort(pair, N, sizeof(Pair), cmp);
		
		/* qsort debug */
		/*
		for( int i = 0; i < N; ++i )
			printf("%d %d\n", pair[i].point[0], pair[i].point[1]);
		*/
		
		int max = 0;
		Pair temp;
		temp.point[0] = pair[0].point[0];
		temp.point[1] = pair[0].point[1];
		for( int i = 0; i < N; ++i )
		{
			if( temp.point[1] >= pair[i].point[0] )
			{
				if( temp.point[1] < pair[i].point[1] )
					temp.point[1] = pair[i].point[1];
			}
			/* imply this is a new segment */
			else
			{
				if( temp.point[1]-temp.point[0] > max )
					max = temp.point[1]-temp.point[0];
				temp.point[0] = pair[i].point[0];
				temp.point[1] = pair[i].point[1];
			}
		}
		if( temp.point[1]-temp.point[0] > max )
			max = temp.point[1]-temp.point[0];
		
		printf("%ld\n", max);
		
		
		delete[] pair;
	}
	
}
