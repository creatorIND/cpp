#include <iostream>
#include <vector>

// Naive Solution - Time Complexity O(N^2)
// int maxSubarraySum(const std::vector<int> &arr, int n)
// {
//     if (n > arr.size())
//     {
//         return -1; // Invalid input
//     }

//     int maxSum{0};

//     for (int i{0}; i <= arr.size() - n; ++i)
//     {
//         int sum {0};
//         for (int j{0}; j < n; ++j)
//         {
//             sum += arr[i + j];
//         }
//         maxSum = std::max(maxSum, sum);
//     }

//     return maxSum;
// }

// Refactored Solution - Time Complexity O(N)
int maxSubarraySum(const std::vector<int> &arr, int n)
{
    if (n > arr.size())
    {
        return -1; // Invalid input
    }

    int maxSum{0};
    int windowSum{0};

    // Calculate the initial window sum of the first n elements
    for (int i{0}; i < n; ++i)
    {
        windowSum += arr[i];
    }

    maxSum = windowSum;

    // Slide the window to the right and update the window sum
    for (int i{n}; i < arr.size(); ++i)
    {
        windowSum += arr[i] - arr[i - n];
        maxSum = std::max(maxSum, windowSum);
    }

    return maxSum;
}

int main()
{
    std::vector<int> arr = {1, 2, 5, 2, 8, 1, 5};
    int n = 2;
    int maxSum = maxSubarraySum(arr, n);
    std::cout << "Maximum sum of " << n << " consecutive elements: " << maxSum << std::endl;

    n = 4;
    maxSum = maxSubarraySum(arr, n);
    std::cout << "Maximum sum of " << n << " consecutive elements: " << maxSum << std::endl;

    // std::cout << maxSubarraySum({4, 2, 1, 6, 2}, 4) << std::endl;

    return 0;
}