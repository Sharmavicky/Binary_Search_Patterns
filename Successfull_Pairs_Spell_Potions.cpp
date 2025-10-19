#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
    * Class Name: Solution
    *
    * Description:
    * -------------
    * This class provides two different approaches to solve the
    * "Successful Pairs of Spells and Potions" problem.
    *
    * For each spell, we need to determine how many potions can form a successful pair
    * such that (spell[i] * potion[j]) >= success.
    *
    * Implemented Approaches:
    * -----------------------
    * 1. LinearSearch (Brute Force):
    *      - Compares every spell with every potion.
    *      - Counts pairs that meet or exceed the success threshold.
    *      - Time Complexity: O(n * m)
    *
    * 2. BinarSearch (Optimized using Binary Search):
    *      - Sorts the potions array.
    *      - For each spell, finds the smallest potion value that satisfies the success condition.
    *      - Uses binary search to efficiently count valid pairs.
    *      - Time Complexity: O(n log m)
    *
    * Space Complexity:
    * -----------------
    * O(n) — for the result vector.
    *
    * Notes:
    * ------
    * - The binary search approach is significantly faster for large input sizes.
    * - Both methods ensure correctness, allowing a clear comparison of performance and logic.
*/

class Solution {
    public:
    vector<int> LinearSearch(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size(), m = potions.size();
        vector<int> res(n, 0);

        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if ((long long) spells[i] * potions[j] >= success) res[i]++;
            }
        }

        return res;
    }

    vector<int> BinarSearch(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end()); // sort the potions array

        int n = spells.size(), m = potions.size();
        vector<int> res(n, 0);

        for (int i=0; i<n; i++) {
            int left = 0, right = m-1;
            while (left <= right) {
                int mid = left + (right - left) / 2;

                if ((long long) potions[mid] * spells[i] >= success) right = mid - 1;
                else left = mid + 1;
            }
            res[i] = m - left;
        }

        return res;
    }
};

// main function
int main() {
    vector<int> spells = {5, 1, 3};
    vector<int> potions = {1, 2, 3, 4, 5};
    long long success = 7;

    vector<int> res = Solution().BinarSearch(spells, potions, success);

    for (int n: res) {
        cout << n << " ";
    }

    return 0;
}