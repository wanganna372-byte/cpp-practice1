#include <iostream>
#include <string>
#include <vector>
using namespace std;

int binary_search_index(const std::vector<int>& values, int target)
{
    std::size_t left = 0;
    std::size_t right = values.size();
    while (left < right) {
        const std::size_t mid = left + (right - left) / 2;
        if (values[mid] < target) {
            left = mid + 1;
        } else if (values[mid] > target) {
            right = mid;
        } else {
            return static_cast<int>(mid);
        }
    }
    return -1;
}

void check(int actual, int expected, const std::string& label)
{
    std::cout << label << ": "
              << (actual == expected ? "PASS" : "FAIL")
              << " (expected " << expected << ", got " << actual << ")\n";
}

int main()
{
    const std::vector<int> values{1, 2, 3, 4, 6};

    check(binary_search_index(values, 5), -1, "missing value");
    check(binary_search_index(values, 3), 2, "middle value");
    check(binary_search_index(values, 1), 0, "first value");
    check(binary_search_index(values, 6), 4, "last value");

    // TODO: Add at least two boundary tests of your own.
    const std::vector<int> empty{};
    check(binary_search_index(empty, 5), -1, "empty vector");

    const std::vector<int> single{42};
    check(binary_search_index(single, 42), 0, "single element found");


    return 0;
}
