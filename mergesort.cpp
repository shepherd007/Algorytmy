#include <cmath>
#include <memory>
#include <climits>

static void merge(int* A, int p, int q, int r)
{
	int n = q-p+1;
	int m = r-q;

	int i,j;

	/*
	Note - it is not optimal solution!
	*/
	int* L = new int[n+1];
	int* R = new int[m+1];

	memset(L, 0, n);
	memset(R, 0, m);

	for(i=0;i<n;i++)
	{
		L[i] = A[p+i];
	}

	for(j=0;j<m;j++)
	{
		R[j] = A[q+j+1];
	}

	L[n] = INT_MAX;
	R[m] = INT_MAX;

	i = 0;
	j = 0;

	for(int k=p; k<=r; k++)
	{
		if(L[i]<=R[j])
		{
			A[k]=L[i];
			i++;
		}
		else
		{
			A[k]=R[j];
			j++;
		}
	}

	delete L;
	delete R;
}

void mergeSort(int* A, int p, int r)
{
	if(p<r)
	{
		int q = floor((float)(p+r)/2);
		mergeSort(A, p, q);
		mergeSort(A, q+1, r);
		merge(A, p, q, r);
	}
}
