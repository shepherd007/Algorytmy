/*
Swaps elements in table
Example: swap(&tab[0], &tab[1])
*/
void swap(int* A, int* B)
{
	if(A != B)
	{
		*A ^= (*B);
		*B ^= (*A);
		*A ^= (*B);
	}
}