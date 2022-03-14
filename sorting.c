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

void merge(int A[], int left, int mid, int right)
{
	int k = left, p = mid + 1, i = 0;
	int T[10];
	while(left <= mid && p <= right)
	{
		if(A[left] <= A[p])
			T[i++] = A[left++];
		else	
			T[i++] = A[p++];
	}
	while(left <= mid)
		T[i++] = A[left++];
	while(p <= right)
		T[i++] = A[p++];
	for(i = k ; i <= right; i++)
		A[i] = T[i - k];
}

void merge_sort(int A[], int left, int right)
{
	if(left < right)
	{
		int mid = (left + right) / 2 ;
		merge_sort(A, left, mid);
		merge_sort(A, mid + 1, right);
		merge(A, left, mid, right);
	}
}

void shell_sort(int A[], int n)
{
	int gap, p, temp, j;
	for(gap = n/2 ; gap > 0 ; gap = gap/2)
	{
		for(p = gap ; p < n ; p++)
		{
			temp = A[p];
			for(j = p ; j >= gap && temp < A[j - gap] ; j = j - gap)	
				A[j] = A[j - gap];
			A[j] = temp;
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
	//merge_sort(nums, 0, n-1);
	//shell_sort(nums, n);
	for(int i = 0 ; i < n ; i++)
		printf("%d\t", nums[i]);
	return 0;
}
