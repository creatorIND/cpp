#include <iostream>
#include <vector>
#include <string>

// Compute the Longest Prefix-Suffix (lps) array
std::vector<int> computeLPS(const std::string &pattern)
{
    int patternSize = pattern.length();
    std::vector<int> lps(patternSize, 0);

    int len = 0; // Length of the previous longest prefix suffix

    for (int i{1}; i < patternSize; ++i)
    {
        while (len > 0 && pattern[i] != pattern[len])
        {
            len = lps[len - 1];
        }

        if (pattern[i] == pattern[len])
        {
            len++;
        }

        lps[i] = len;
    }

    return lps;
}

// KMP string search algorithm
void kmpStringSearch(const std::string &text, const std::string &pattern)
{
    int textSize = text.length();
    int patternSize = pattern.length();

    std::vector<int> lps = computeLPS(pattern);

    int i{0}; // index for text[]
    int j{0}; // index for pattern[]

    while (i < textSize)
    {
        if (pattern[j] == text[i])
        {
            i++;
            j++;
        }

        if (j == patternSize)
        {
            std::cout << "Pattern found at index " << i - j << std::endl;
            j = lps[j - 1];
        }
        else if (i < textSize && pattern[j] != text[i])
        {
            if (j != 0)
            {
                j = lps[j - 1];
            }
            else
            {
                i++;
            }
        }
    }
}

int main()
{
    std::string text = "This is a text with the pattern 'text'";
    std::string pattern = "text";

    kmpStringSearch(text, pattern);

    return 0;
}