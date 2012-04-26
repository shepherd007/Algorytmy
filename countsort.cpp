// CountingSort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

int A[] = {13, 19, 9, 5, 12, 8, 7, 4, 11, 2, 6, 21};
int len = sizeof(A)/sizeof(A[0]);

int B[12];
int C[21];

int K = 21;

void countingSort()
{
    memset(C,0,sizeof(C));

    for(int i=0;i<len;i++)
    {
        C[A[i]] += 1;
    }

    for(int i=1; i<K; i++)
    {
        C[i] += C[i-1];
    }

    for(int i=len-1; i>=0; i--)
    {
        B[C[A[i]-1]] = A[i];
        C[A[i]-1] -= 1;
    }
}

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

int randomizedSelect(int p, int r, int i)
{
    if(p == r)
    {
        return A[p];
    }

    int q = randomizedPartition(p, r);
    int k = q - p + 1;

    if(i<=k)
    {
        randomizedSelect(p,q,i);
    }
    else
    {
        randomizedSelect(q+1,r,i-k);
    }
}

int _tmain(int argc, _TCHAR* argv[])
{
   // countingSort();
    int x = randomizedSelect(0,12,3);
	return 0;
}

