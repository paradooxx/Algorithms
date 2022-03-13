#include <iostream>

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

int main()
{
	int nums[] = {5, 2, 4, 6, 1, 3, -1 };
	int n = sizeof(nums)/sizeof(nums[0]);
	sort(nums, n);
	for(int i = 0 ; i < n ; i++)
		std::cout << nums[i] << ", " ;
	return 0;
}