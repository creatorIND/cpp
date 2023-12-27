#include <iostream>
#include <vector>

// Merge two sorted subarrays into one sorted array
void merge(std::vector<int> &arr, int left, int mid, int right)
{
    int n1{mid - left + 1};
    int n2{right - mid};

    std::vector<int> L(n1);
    std::vector<int> R(n2);

    for (int i{0}; i < n1; ++i)
        L[i] = arr[left + i];

    for (int j{0}; j < n2; ++j)
        R[j] = arr[mid + 1 + j];

    int i{0}, j{0}, k{left};

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            ++i;
        }
        else
        {
            arr[k] = R[j];
            ++j;
        }
        ++k;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        ++i;
        ++k;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        ++j;
        ++k;
    }
}

// Merge Sort function
void mergeSort(std::vector<int> &arr, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

int main()
{
    std::vector<int> arr{12, 11, 13, 5, 6, 7};

    std::cout << "Original array: ";
    for (int num : arr)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    mergeSort(arr, 0, arr.size() - 1);

    std::cout << "Sorted array: ";
    for (int num : arr)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}