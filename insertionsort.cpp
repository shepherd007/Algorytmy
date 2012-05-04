void insertionSort(int* A, int len)
{
	/*
	Complexity: O(n)
	*/
	for(int j=1; j<len;j++)
	{
		int key = A[j];

		int i = j - 1;

		while(i>=0 && A[i]>key)
		{
			A[i+1] = A[i];
			i--;
		}
		A[i+1] = key;
	}
}