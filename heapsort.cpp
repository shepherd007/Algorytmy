int A[] = {0,1,3,2,4,5};
int heapSize = sizeof(A)/sizeof(A[0]);
  
void heapify(int i)
{
    int left_index = 2*i;
    int right_index = 2*i+1;

    int largest = i;
    int len = sizeof(A)/sizeof(A[0]);

    if(left_index < heapSize &&
       A[left_index] > A[i])
    {
        largest = left_index;
    }

    if(right_index < heapSize &&
       A[right_index] > A[largest])
    {
        largest = right_index;
    }

    if(largest != i)
    {
        int tmp = A[i];
        A[i] = A[largest];
        A[largest] = tmp;

        heapify(largest);
    }
}

void buildHeap()
{
    int len = (sizeof(A)/sizeof(A[0]))/2 + 1;
    heapSize = sizeof(A)/sizeof(A[0]);
    for(int i=len; i>0; i--)
    {
        heapify(i);
    }
}

void heapSort()
{
    int len = (sizeof(A)/sizeof(A[0]));

    buildHeap();
    for(int i=len-1; i>=2; i--)
    {
        int tmp = A[i];
        A[i] = A[1];
        A[1] = tmp;
        heapSize--;
        heapify(1);
    }
}

void insert(int v)
{
    heapSize+=1;
    int i=heapSize;

    while(i>1 && A[i/2] < v)
    {
        int tmp = A[i];
        A[i] = A[i/2];
        A[i/2] = A[i];
        i = i/2;
    }

    A[i] = v;
}

#if 0
int _tmain(int argc, _TCHAR* argv[])
{
   // heapSort();
   // buildHeap();
    //insert(9);
    heapSort();
	return 0;
}
#endif