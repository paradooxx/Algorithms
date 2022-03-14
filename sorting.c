#include <stdio.h>
#include <stdlib.h>

void insertion_sort(int A[], int n)
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

// not so efficient bubble sorting(exchange sorting)
void bubble_sort(int A[], int n)       
{
	int temp, i, j;
	for(i = 0 ; i < n - 1 ; i++)
	{
		for(j = 0 ; j < n - 1 ; j++)
		{
			if(A[j] > A[j + 1])
			{
				temp = A[j];
				A[j] = A[j + 1];
				A[j + 1] = temp;
			}
		}
	}
}

//improved bubble sorting
void Bubble_Sort(int A[], int n)
{
	int i, j, flag = 1, temp;
	for(i = 0 ; i < n - 1 && flag == 1 ; i++)
	{
		flag = 0;
		for(j = 0 ; j < n - 1 - i ; j++)
		{
			if(A[j] > A[j + 1])
			{
				temp = A[j];
				A[j] = A[j + 1];
				A[j + 1] = temp;
				flag = 1;
			}
		}
	}
}

int main()
{
	int nums[] = {5, 2, 4, 6, 1, 3, -1 };
	int n = sizeof(nums)/sizeof(nums[0]);
	//insertion_sort(nums, n);
	//selection_sort(nums, n);
	//bubble_sort(nums, n);
	//Bubble_Sort(nums, n);
	for(int i = 0 ; i < n ; i++)
		printf("%d\t", nums[i]);
	return 0;
}
