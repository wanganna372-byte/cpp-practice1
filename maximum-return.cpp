#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


int max_crossing_sum(const std::vector<int>& changes,
                     int low, int mid, int high)
{
    // TODO: Find the best non-empty subarray that crosses mid.
    (void)changes;
    (void)low;
    (void)mid;
    (void)high;
    
    // 从 mid 往左累加，找最大左后缀和
    int left_best = changes[mid];
    int sum = 0;
    for (int i = mid; i >= low; --i) {
        sum += changes[i];
        left_best=max(left_best,sum);
    }

    // 从 mid+1 往右累加，找最大右前缀和
    int right_best = changes[mid + 1];
    sum = 0;
    for (int j = mid + 1; j <= high; ++j) {
        sum += changes[j];
        right_best=max(right_best,sum);
    }

    return left_best + right_best;
}


int max_subarray_sum(const std::vector<int>& changes, int low, int high)
{
    // TODO: Implement the divide-and-conquer recurrence.
    (void)changes;
    (void)low;
    (void)high;

    if (low == high) {
        return changes[low];
    }

    int mid = low + (high - low) / 2;

    int left_best  = max_subarray_sum(changes, low, mid);
    int right_best = max_subarray_sum(changes, mid + 1, high);
    int cross_best = max_crossing_sum(changes, low, mid, high);

    return max({left_best, right_best, cross_best});
}

int maximum_return(const std::vector<int>& prices)
{
    if (prices.size() < 2) {
        throw std::invalid_argument("at least two prices are required");
    }

    std::vector<int> changes(prices.size() - 1);
    for (std::size_t i = 0; i < changes.size(); ++i) {
        changes[i] = prices[i + 1] - prices[i];
    }

    return max_subarray_sum(changes, 0, static_cast<int>(changes.size()) - 1);
}

void check(int actual, int expected, const std::string& label)
{
    std::cout << label << ": "
              << (actual == expected ? "PASS" : "FAIL")
              << " (expected " << expected << ", got " << actual << ")\n";
}

int main()
{
    check(maximum_return({100, 113, 110, 85, 105, 102, 86, 63, 81,
                          101, 94, 106, 101, 79, 94, 90, 97}),
          43,
          "crossing optimum");
    check(maximum_return({1, 2, 3, 4, 5}), 4, "increasing prices");
    check(maximum_return({9, 7, 4, 1}), -2, "decreasing prices");
    check(maximum_return({5, 8}), 3, "two prices");

    // TODO: Add at least one test of your own.
    check(maximum_return({1, 4, 2, 7}), 6, "best is non-crossing left");
    check(maximum_return({3, 1, 4, 1, 5}), 4, "must-trade with fluctuations");
    return 0;
}