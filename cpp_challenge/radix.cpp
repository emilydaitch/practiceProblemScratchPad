#include <iostream>
#include <chrono> 
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
 
void radixSort(int arr[], int n)
{
	int digit, p;
	p = getMaximum(arr, n);
 
	for (digit = 1; p/digit > 0; digit *= 10)
		countSort(arr, n, digit);
}
 
int main()
{
	std::cout << "Hello Radix" << std::endl;
	int i;
	int len1 = std::pow(10,5) * .125;
	int len2 = std::pow(10,5) * .25;
	int len4 = std::pow(10,5) * .5;
	int len8 = std::pow(10,5);
	int arr1[len1];
	int arr2[len2];
	int arr4[len4];
	int arr8[len8];
	for(i = 0; i < len1; i++)
	{
		arr1[i] = rand() % 500;
	}
        for(i = 0; i < len2; i++)
        {
                arr2[i] = rand() % 500;
        }
        for(i = 0; i < len4; i++)
        {
                arr4[i] = rand() % 500;
        }
        for(i = 0; i < len8; i++)
        {
                arr8[i] = rand() % 500;
        }
        
	auto begin1 = std::chrono::high_resolution_clock::now();    
    	radixSort(arr1, len1);
    	auto end1 = std::chrono::high_resolution_clock::now();    
    	auto dur1 = end1 - begin1;
        auto begin2 = std::chrono::high_resolution_clock::now();
        radixSort(arr2, len2);
        auto end2 = std::chrono::high_resolution_clock::now();
        auto dur2 = end2 - begin2;
        auto begin4 = std::chrono::high_resolution_clock::now();
        radixSort(arr4, len4);
        auto end4 = std::chrono::high_resolution_clock::now();
        auto dur4 = end4 - begin4;
        auto begin8 = std::chrono::high_resolution_clock::now();
        radixSort(arr8, len8);
        auto end8 = std::chrono::high_resolution_clock::now();
        auto dur8 = end8 - begin8;

    	auto ms1 = std::chrono::duration_cast<std::chrono::microseconds>(dur1).count();
	auto ms2 = std::chrono::duration_cast<std::chrono::microseconds>(dur2).count();
	auto ms4 = std::chrono::duration_cast<std::chrono::microseconds>(dur4).count();
	auto ms8 = std::chrono::duration_cast<std::chrono::microseconds>(dur8).count();

	std::cout << "Radix sort took " << ms1 << " microseconds to sort 12,500 integers" << std::endl;
        std::cout << "Radix sort took " << ms2 << " microseconds to sort 25,000 integers" << std::endl; 
        std::cout << "Radix sort took " << ms4 << " microseconds to sort 50,000 integers" << std::endl;	
        std::cout << "Radix sort took " << ms8 << " microseconds to sort 100,000 integers" << std::endl;}
