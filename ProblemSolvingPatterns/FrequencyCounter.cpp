#include <iostream>
#include <unordered_map>
#include <vector>

// Naive Solution - Time Complexity O(N^2)
// bool same(const std::vector<int> &arr1, std::vector<int> &arr2)
// {
//     if (arr1.size() != arr2.size())
//     {
//         return false;
//     }

//     for (int num1 : arr1)
//     {
//         bool found{false};
//         for (int i{0}; i < arr2.size(); i++)
//         {
//             if (arr2[i] == num1 * num1)
//             {
//                 arr2[i] = -1; // Mark as visited to handle frequency
//                 found = true;
//                 break;
//             }
//         }
//         if (!found)
//         {
//             return false;
//         }
//     }
//     return true;
// }

// Refactored Solution - Time Complexity O(N)
bool same(const std::vector<int> &arr1, const std::vector<int> &arr2)
{
    if (arr1.size() != arr2.size())
    {
        return false;
    }

    std::unordered_map<int, int> frequencyCounter;

    for (int num : arr2)
    {
        frequencyCounter[num]++;
    }

    for (int num : arr1)
    {
        int squared = num * num;
        if (frequencyCounter[squared] > 0)
        {
            frequencyCounter[squared]--;
        }
        else
        {
            return false;
        }
    }

    return true;
}

int main()
{
    std::vector<int> arr1 = {1, 2, 3, 2, 5};
    std::vector<int> arr2 = {9, 1, 4, 4, 25};

    std::cout << same(arr1, arr2) << std::endl;

    // std::cout << same({1, 2, 1}, {4, 4, 1}) << std::endl;

    return 0;
}