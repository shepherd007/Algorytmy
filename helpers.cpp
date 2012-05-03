/*
Swaps elements in table
Example: swap(&tab[0], &tab[1])
*/
void swap(int* A, int* B)
{
	*A = (*A) ^ (*B);
	*B = (*B) ^ (*A);
	*A = (*B) ^ (*A);
}