// Note: Since C++11, the STL has std::array which is a template-based array class
// Use std::array instead of raw arrays whenever possible

// Note that we can have non-type template parameters
// That's what N is in this case

#include <iostream>
#include <string>

template<typename T, int N>
class Array {
    int size {N}; // how do we get the N??
    T values[N]; // the N needs to be known at compile time!

    friend std::ostream &operator<<(std::ostream &os, const Array<T, N> &arr) {
        os << "[ ";
        for(const auto &val: arr.values)
            os << val << " ";
        os << "]" << std::endl;
        return os;
    }

    public:
    Array() = default;
    Array(T initValue) {
        for(auto &item: values)
            item = initValue;
    }
    void fill(T val) {
        for(auto &item: values)
            item = val;
    }
    int getSize() const {
        return size;
    }
    // overloaded subscript operator for easy use
    T &operator[](int index) {
        return values[index];
    }
};

int main() {
    Array<int, 5> nums;
    std::cout << "The size of nums is: " << nums.getSize() << std::endl;
    std::cout << nums << std::endl;

    nums.fill(0);
    std::cout << "The size of nums is: " << nums.getSize() << std::endl;
    std::cout << nums << std::endl;

    nums.fill(10);
    std::cout << nums << std::endl;

    nums[0] = 1000;
    nums[3] = 2000;
    std::cout << nums << std::endl;

    Array<int, 100> nums2 {1};
    std::cout << "The size of num2 is: " << nums2.getSize() << std::endl;
    std::cout << nums2 << std::endl;

    Array<std::string, 10> strings(std::string {"Creator"});
    std::cout << "The size of strings is: " << strings.getSize() << std::endl;
    std::cout << strings << std::endl;

    strings[0] =  std::string {"Sujal"};
    std::cout << strings << std::endl;

    strings.fill(std::string {"X"});
    std::cout << strings << std::endl;

    return 0;
}