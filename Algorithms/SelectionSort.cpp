#include <iostream>
#include <vector>

void selectionSort(std::vector<int> &arr)
{
    int n = arr.size();

    for (int i{0}; i < n - 1; i++)
    {
        int minIndex{i};

        // Find the minimum element in the unsorted portion of the array
        for (int j{i + 1}; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }

        // Swap the minimum element with the first element in the unsorted portion
        std::swap(arr[i], arr[minIndex]);
    }
}

int main()
{
    std::vector<int> arr{64, 34, 25, 12, 22, 11, 90};

    std::cout << "Original array: ";
    for (int num : arr)
    {
        std::cout << num << " ";
    }

    selectionSort(arr);

    std::cout << "\nSorted array: ";
    for (int num : arr)
    {
        std::cout << num << " ";
    }

    std::cout << std::endl;
    return 0;
}