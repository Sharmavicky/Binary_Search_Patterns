#include <iostream>
#include <vector>
using namespace std;

/*

    * Solves the "First Bad Version" problem using binary search.
    
    * - A private variable `badVersion` simulates the first bad version.
    * - The helper function `isBadVersion(int n)` mimics the provided API:
    *      returns true if version n is bad, false otherwise.
    
    * - The public method `firstBadVersion(int n)` finds the earliest version
    *   that is bad in the range [1..n]:
    *      * If mid is bad → store it as a candidate and move left.
    *      * If mid is good → move right.
    
    * Time Complexity: O(log n)  (binary search halves the range each step)
    * Space Complexity: O(1)
*/


class Solution {
    private: 
    int badVersion = 10;

    bool isBadVersion(int n) {
        return n >= badVersion ? true : false;
    }

    public:
    int firstBadVersion(int n) {
        int left = 1, right = n;
        int firstBadVersion = 0;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (isBadVersion(mid)) {
                firstBadVersion = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return firstBadVersion;
    }
};

// main function
int main() {
    int num = 100;

    int result = Solution().firstBadVersion(num);
    cout << result;
    return 0;
}