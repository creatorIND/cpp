#include <iostream>
#include <vector>

// Naive Solution - Time Complexity O(N^2)
// std::vector<int> sumZero(const std::vector<int> &arr)
// {
//     for (int i{0}; i < arr.size() - 1; ++i)
//     {
//         for (int j{i + 1}; j < arr.size(); ++j)
//         {
//             if (arr[i] + arr[j] == 0)
//             {
//                 return {arr[i], arr[j]};
//             }
//         }
//     }

//     return {}; // Return an empty vector if no pair with sum 0 is found
// }

// Refactored Solution - Time Complexity O(N)
// Array must be sorted!
std::vector<int> sumZero(const std::vector<int> &arr)
{
    int left{0};
    int right = arr.size() - 1;

    while (left < right)
    {
        int sum = arr[left] + arr[right];
        if (sum == 0)
        {
            return {arr[left], arr[right]};
        }
        else if (sum < 0)
        {
            left++;
        }
        else
        {
            right--;
        }
    }

    return {}; // Return an empty vector if no pair with sum 0 is found
}

int main()
{
    std::vector<int> arr = {-3, -2, -1, 0, 1, 2, 3};
    std::vector<int> result = sumZero(arr);
    if (!result.empty())
    {
        std::cout << "{" << result[0] << " " << result[1] << "}" << std::endl;
    }
    else
    {
        std::cout << "Not found!" << std::endl;
    }

    return 0;
}