#include <iostream>
#include <vector>

void bubbleSort(std::vector<int> &arr)
{
    int n = arr.size();
    bool swapped;

    for (int i{0}; i < n - 1; i++)
    {
        swapped = false;

        // Last i elements are already in place, so no need to check them
        for (int j{0}; j < (n - i - 1); j++)
        {
            // Swap if the element found is greater than the next element
            if (arr[j] > arr[j + 1])
            {
                std::swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        // If no two elements were swapped in the inner loop, the array is already sorted
        if (!swapped)
        {
            break;
        }
    }
}

int main()
{
    std::vector<int> arr{12, 34, 25, 64, 90, 22, 11};
    std::cout << "Original array: ";
    for (int num : arr)
    {
        std::cout << num << " ";
    }

    bubbleSort(arr);
    std::cout << "\nSorted array: ";
    for (int num : arr)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}