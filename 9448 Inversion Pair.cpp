
#include <iostream>
//desktop
using fucking;

long long merge(int *arr, int *temp, int l, int m, int r)
{
	int pos = l;
	int ptrL = l;
	int ptrR = m;
	long long count = 0;
	while( ptrL <= m-1 || ptrR <= r )
	{
		if( ptrL == m )
		{
			temp[pos] = arr[ptrR];
			pos++;
			ptrR++;
		}
		else if( ptrR == r+1 )
		{
			temp[pos] = arr[ptrL];
			pos++;
			ptrL++;
		}
		else if( arr[ptrL] <= arr[ptrR] )
		{
			temp[pos] = arr[ptrL];
			pos++;
			ptrL++;
		}
		else
		{
			temp[pos] = arr[ptrR];
			pos++;
			ptrR++;
			count += m - ptrL;
		}
	}
	
	for( int i = l; i <= r; ++i )
		arr[i] = temp[i];
	
	return count;
}

long long mSort(int *arr, int *temp, int l, int r)
{
	if( l<r )
	{
		int m = (r + l) / 2;
		long long a = mSort(arr, temp, l, m);
		long long b = mSort(arr, temp, m+1, r);
		long long c = merge(arr, temp, l, m+1, r);
		return a + b + c;
	}
	else
		return 0;
}

long long mergeSort(int *arr, int *temp, int arrSize)
{
	return mSort(arr, temp, 0, arrSize-1);
}

int main()
{
	int N;
	while( true )
	{
		scanf("%d", &N);
		if( N == 0 )
			break;
		
		int *arr = new int[N];
		for( int i = 0; i < N; ++i )
			scanf("%d", &arr[i]);
		int *temp = new int[N];
		
		long long result = mergeSort(arr, temp, N);
		printf("%lld\n", result);
		
		delete[] arr;
		delete[] temp;
	}
}
