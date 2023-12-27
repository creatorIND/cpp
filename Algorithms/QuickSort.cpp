#include <iostream>
#include <vector>

// Partition function to rearrange elements such that elements smaller than pivot are on the left
// and elements greater than pivot are on the right
int partition(std::vector<int> &arr, int low, int high)
{
    int pivot = arr[high]; // choose the last element as the pivot
    int i = low - 1;       // index of smaller element

    for (int j = low; j <= high - 1; ++j)
    {
        if (arr[j] < pivot)
        {
            ++i;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);

    return i + 1;
}

// Quick Sort function
void quickSort(std::vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int pivotIndex = partition(arr, low, high);

        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

int main()
{
    std::vector<int> arr{10, 7, 8, 9, 1, 23, 8};

    std::cout << "Original array: ";
    for (int num : arr)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    int n = arr.size();
    quickSort(arr, 0, n - 1);

    std::cout << "Sorted array: ";
    for (int num : arr)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}