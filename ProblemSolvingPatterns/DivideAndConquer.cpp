/*
Given a sorted array of integers, write a function called `search`, that accepts a value and returns the index where the value passed to the function is located. If the value is not found, return -1.
*/

#include <iostream>
#include <vector>

// Naive Solution - Time Complexity O(N)
// int search(const std::vector<int> &sortedArray, int value)
// {
//     for (int i = 0; i < sortedArray.size(); ++i)
//     {
//         if (sortedArray[i] == value)
//         {
//             return i;
//         }
//     }
//     return -1;
// }

// Refactored Solution - Time Complexity O(log N)
int binarySearch(const std::vector<int> &sortedArray, int value, int left, int right)
{
    if (left > right)
        return -1;

    int mid = left + (right - left) / 2;

    if (sortedArray[mid] == value)
    {
        return mid;
    }
    else if (sortedArray[mid] > value)
    {
        return binarySearch(sortedArray, value, left, mid - 1);
    }
    else
    {
        return binarySearch(sortedArray, value, mid + 1, right);
    }
}

int search(const std::vector<int> &sortedArray, int value)
{
    return binarySearch(sortedArray, value, 0, sortedArray.size() - 1);
}

int main()
{
    std::vector<int> sortedArray = {1, 3, 5, 7, 9, 11, 13, 15, 17};
    int value = 11;
    int index = search(sortedArray, value);
    std::cout << "Value " << value << " is at index: " << index << std::endl;

    // std::cout << search({1, 2, 3, 4, 5, 6}, 11) << std::endl;

    return 0;
}