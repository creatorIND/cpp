#include <iostream>
#include <unordered_map>
#include <vector>

class HashTable
{
private:
    std::unordered_map<int, int> table;

public:
    void insert(int key, int value)
    {
        table[key] = value;
    }

    bool search(int key, int &value)
    {
        if (table.count(key))
        {
            value = table[key];
            return true;
        }
        return false;
    }

    bool remove(int key)
    {
        if (table.count(key))
        {
            table.erase(key);
            return true;
        }
        return false;
    }

    std::vector<int> getAllKeys()
    {
        std::vector<int> keys;
        for (const auto &entry : table)
        {
            keys.push_back(entry.first);
        }
        return keys;
    }

    std::vector<int> getAllValues()
    {
        std::vector<int> values;
        for (const auto &entry : table)
        {
            values.push_back(entry.second);
        }
        return values;
    }
};

int main()
{
    HashTable ht;

    ht.insert(5, 10);
    ht.insert(15, 20);
    ht.insert(25, 30);

    int value{};
    if (ht.search(15, value))
    {
        std::cout << "Found value: " << value << std::endl;
    }
    else
    {
        std::cout << "Value not found!" << std::endl;
    }

    if (ht.remove(15))
    {
        std::cout << "Key 15 removed" << std::endl;
    }
    else
    {
        std::cout << "Key not found!" << std::endl;
    }

    if (ht.search(15, value))
    {
        std::cout << "Found value: " << value << std::endl;
    }
    else
    {
        std::cout << "Value not found!" << std::endl;
    }

    return 0;
}