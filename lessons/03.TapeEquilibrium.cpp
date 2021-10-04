#include <algorithm>
#include <functional>
#include <iterator>
#include <numeric>
#include <cmath>

int solution(vector<int> &A) {
    auto partial_sum_right = std::vector<int>(A.size() - 1);
    auto partial_sum_left = std::vector<int>(A.size() - 1);
    std::partial_sum(A.begin(), A.end() - 1, partial_sum_right.begin());
    std::partial_sum(A.rbegin(), A.rend() - 1, partial_sum_left.begin());
    auto diffs = std::vector<int>(A.size() - 1);
    auto min_abs = [](auto lhs, auto rhs){ return std::abs(lhs - rhs); };
    std::transform(partial_sum_right.begin(), partial_sum_right.end(),
                   partial_sum_left.rbegin(),
                   diffs.begin(),
                   min_abs);
    auto it_min = std::min_element(diffs.begin(), diffs.end());
    return *it_min;
}
