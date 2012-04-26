// Quicksort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdlib.h>

int A[] = {13, 19, 9, 5, 12, 8, 7, 4, 11, 2, 6, 21};

int partition(int p, int r)
{
    int i = p - 1;
    int j = r + 1;
    int x = A[p];

    while(1)
    {
        do
        {
            j--;
        } while(A[j] > x);

        do
        {
            i++;
        } while(A[i] < x);

        if(i < j)
        {
            int tmp = A[j];
            A[j] = A[i];
            A[i] = tmp;
        }
        else
        {
            return j;
        }
    }
}

int randomizedPartition(int p, int r)
{
    int len = r-p;
    int i = rand()%len + p;
    int tmp = A[i];
    A[i] = A[p];
    A[p] = tmp;

    return partition(p, r);
}

int lomutoPartition(int p, int r)
{
    int x = A[r];
    int i = p - 1;

    for(int j=p; j<=r; j++)
    {
        if(A[j] <= x)
        {
            i++;
            int tmp = A[i];
            A[i] = A[j];
            A[j] = tmp;
        }
    }

    if(i<r)
    {
        return i;
    }
    else
    {
        return i-1;
    }
}

void quicksort(int p, int r)
{
    if(p < r)
    {
        int q = lomutoPartition(p, r);
        quicksort(p, q);
        quicksort(q+1, r);
    }
}

void randomizedQuicksort(int p, int r)
{
    if(p < r)
    {
        int q = randomizedPartition(p, r);
        randomizedQuicksort(p, q);
        randomizedQuicksort(q+1, r);
    }

}
int _tmain(int argc, _TCHAR* argv[])
{
    quicksort(0,11);
	return 0;
}

