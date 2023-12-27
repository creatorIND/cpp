#include <iostream>
#include <vector>

// Find the maximum value in the array
int getMax(const std::vector<int> &arr)
{
    int max = arr[0];
    for (int i{1}; i < arr.size(); ++i)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        };
    }

    return max;
}

// Counting Sort for a specific digit
void countingSort(std::vector<int> &arr, int exp)
{
    int n = arr.size();
    std::vector<int> output(n);
    std::vector<int> count(10, 0);

    for (int i{0}; i < n; ++i)
    {
        count[(arr[i] / exp) % 10]++;
    }

    for (int i{1}; i < 10; i++)
    {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; --i)
    {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for (int i{0}; i < n; ++i)
    {
        arr[i] = output[i];
    }
}

// Radix Sort function
void radixSort(std::vector<int> &arr)
{
    int max = getMax(arr); // find the maximum value in the array

    for (int exp{1}; max / exp > 0; exp *= 10)
    {
        countingSort(arr, exp);
    }
}

int main()
{
    std::vector<int> arr{170, 45, 75, 90, 802, 24, 2, 66};

    std::cout << "Original array: ";
    for (int num : arr)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    radixSort(arr);

    std::cout << "Sorted array: ";
    for (int num : arr)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}