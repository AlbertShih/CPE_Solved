
#include <iostream>
#include <cstdlib>

using namespace std;

int cmp(const void *p, const void *q)
{
	int a = *(int*)p;
	int b = *(int*)q;
	return a-b;
}

int main()
{
	int lenA, lenB;
	while( scanf("%d", &lenA) != EOF )
	{
		if( lenA == 0 )
			break;
		
		int *arrA = new int[lenA];
		for( int i = 0; i < lenA; ++i )
			scanf("%d", &arrA[i]);
		scanf("%d", &lenB);
		int *arrB = new int[lenB];
		for( int i = 0; i < lenB; ++i )
			scanf("%d", &arrB[i]);
		
		qsort(arrA, lenA, sizeof(int), cmp);
		qsort(arrB, lenB, sizeof(int), cmp);
		
		int ptrA = 0, ptrB = 0;
		bool empty = true;
		bool first = true;
		while( ptrA < lenA && ptrB < lenB )
		{
			if( arrA[ptrA] == arrB[ptrB] )
			{
				empty = false;
				if( first )
				{
					first = false;
					printf("%d", arrA[ptrA]);
				}
				else
					printf(" %d",arrA[ptrA]);
				ptrA++;
				ptrB++;
			}
			else if( arrA[ptrA] > arrB[ptrB] )
				ptrB++;
			else
				ptrA++;
		}
		
		if( empty )
			printf("empty\n");
		else
			printf("\n");
		
		delete[] arrA;
		delete[] arrB;
	}
}
