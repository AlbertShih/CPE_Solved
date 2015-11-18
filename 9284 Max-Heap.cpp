
#include <iostream>
#include <cstring>

using namespace std;

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/* heap[0] denotes size of heap */
/* heap[1] denotes the root */
int heap[10010] = {0};

void insertHeap(int val)
{
	heap[0]++;
	heap[heap[0]] = val;
	int t = heap[0];
	while( t/2 >= 1 )
	{
		if( heap[t] > heap[t/2] )
			swap(&heap[t], &heap[t/2]);
		else
			break;
		t /= 2;
	}
}

void extractHeap()
{
	if( heap[0] == 0 )
		return;
	heap[1] = heap[heap[0]];
	heap[0]--;
	int t = 1;
	while( t*2 <= heap[0] )
	{
		if( t*2 == heap[0] )
		{
			if( heap[t] < heap[t*2] )
			{
				swap(&heap[t], &heap[t*2]);
				t = t * 2;
			}
			else
				break;
		}
		else
		{
			if( heap[t*2] > heap[t*2+1] )
				if( heap[t] < heap[t*2] )
				{
					swap(&heap[t], &heap[t*2]);
					t = t * 2;
				}
				else
					break;
			else
				if( heap[t] < heap[t*2+1] )
				{
					swap(&heap[t], &heap[t*2+1]);
					t = t * 2 + 1;
				}
				else
					break;
		}
	}
}

void printRootHeap()
{
	if( heap[0] == 0 )
		printf("Null\n");
	else
		printf("%d\n", heap[1]);
}

int main()
{
	char cmd[20];
	while( scanf("%s", cmd) != EOF )
	{
		if( !strcmp(cmd, "PUSH") )
		{
			int temp;
			scanf("%d", &temp);
			insertHeap(temp);
		}
		else if( !strcmp(cmd, "POP") )
			extractHeap();
		else
			printRootHeap();
	}
}
