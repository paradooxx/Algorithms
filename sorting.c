#include <stdio.h>
#include <stdlib.h>

void sort(int A[], int n)
{
	for(int j = 1 ; j < n ; j++)
	{
		int key = A[j];
		int i = j - 1;
		while(i >= 0 && A[i] > key)
		{
			A[i + 1] = A[i];
			i--;
		}
		A[i + 1] = key;
	}
}

void selection_sort(int A[], int n)
{
	for(int i = n - 1 ; i > 0 ; i--)
	{
		int max = A[0], index = 0;
		for(int j = 1 ; j <= i ; j++)
		{
			if(A[j] > max)
			{
				max = A[j];
				index = j;
			}
		}
		A[index] = A[i];
		A[i] = max;
	}	
}


int main()
{
	int nums[] = {5, 2, 4, 6, 1, 3, -1 };
	int n = sizeof(nums)/sizeof(nums[0]);
	sort(nums, n);
	for(int i = 0 ; i < n ; i++)
		printf("%d\t", nums[i]);
	return 0;
}
