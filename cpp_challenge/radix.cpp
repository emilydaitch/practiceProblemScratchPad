#include <iostream>
#include <ctime> 
#include <cmath>

int getMaximum(int arr[], int len)
{
	int maximum = arr[0];
	for (int i = 1; i < len; i++)
		if (arr[i] > maximum)
			maximum = arr[i];
	return maximum;
}
 
void countSort(int arr[], int len, int digit)
{
	int result[len], i, count[10] = {0};
 
	for (i = 0; i < len; i++)
		count[(arr[i] / digit) % 10]++;
	for (i = 1; i < 10; i++)
		count[i] += count[i-1];
	for (i = len - 1; i >= 0; i--)
	{
		result[count[(arr[i] / digit) % 10] - 1] = arr[i];
		count[(arr[i] / digit) % 10]--;
	}
	for (i = 0; i < len; i++)
		arr[i] = result[i];
}
 
void radixsort(int arr[], int n)
{
	int digit, p;
	p = getMaximum(arr, n);
 
	for (digit = 1; p/digit > 0; digit *= 10)
		countSort(arr, n, digit);
}
 
int main()
{
	std::cout << "Hello Radix" << std::endl;
	int len, i;
	len = std::pow(10,6);

	int arr[len];
	for(i = 0; i < len; i++)
	{
		arr[i] = rand() % 500;
	}
        
        std::time_t result = std::time(nullptr);
	radixsort(arr, len);
	std::time_t result2 = std::time(nullptr);
	std::cout << "Radix sort took " << result2 - result << " milliseconds to sort one million integers" << std::endl;
 
	
}
