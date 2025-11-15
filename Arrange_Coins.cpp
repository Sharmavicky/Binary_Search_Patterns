#include <bits/stdc++.h>
using namespace std;

/*
    * @class Solution
    * @brief Computes how many complete staircase rows can be formed using n coins.
    *
    * This class provides an efficient binary search solution to determine the
    * maximum number of full rows in a coin staircase. Each k-th row requires k coins,
    * and the total coins needed for k rows is given by the formula:
    *
    *      k * (k + 1) / 2
    *
    * Using binary search on the range [0, n], the algorithm finds the largest `k`
    * such that the total required coins do not exceed `n`.
    *
    * Time Complexity: O(log n)
    * Space Complexity: O(1)
*/

class Solution {
    public:
    int arrangeCoins(int n) {
        long long left = 0, right = n;
        long long ans = 0;

        while (left <= right) {
            long long mid = left + (right - left) / 2;
            long long curr = mid * (mid + 1) / 2;

            if (curr == n) {
                return mid;
            } else if (curr < n) {
                ans = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return ans;
    }
};