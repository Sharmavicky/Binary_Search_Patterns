#include <iostream>
#include <vector>
using namespace std;

/*
    * This class implements an efficient O(log n) binary search algorithm to find the
    * single non-duplicate element in a sorted array where every other element appears twice.
    *
    * Key Idea:
    * - In a properly paired array, duplicates occupy even-odd index positions (e.g., nums[0]==nums[1], nums[2]==nums[3], ...).
    * - By checking the parity of the mid index, we can decide which half to discard and continue the search.
    * - The algorithm keeps narrowing down until the unique element is found.
    *
    * Example:
    * Input:  [1,1,2,3,3,4,4,8,8]
    * Output: 2
*/

class Solution {
    public:
    int singleNonDuplicate(vector<int>& nums) {
        int length = nums.size();
        if (length == 1)return nums[0];

        int left = 0, right = length - 1;
        while (left <= right ){
            int mid = left + (right - left) / 2;

            if (mid == 0 && nums[mid] != nums[mid + 1]) return nums[mid];
            if (mid == length - 1 && nums[mid] != nums[mid - 1]) return nums[mid];

            if (nums[mid - 1] != nums[mid] && nums[mid] != nums[mid + 1]) {
                return nums[mid];
            } else if (mid % 2 != 0) { // both left & right halves are odd
                if (nums[mid] == nums[mid - 1]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            } else { // both left & right halves are even
                if (nums[mid] == nums[mid - 1]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
        }

        return -1;
    }
};

// main function
int main() {
    vector<int> n = {1, 1, 2, 2, 3, 4, 4};
    int res = Solution().singleNonDuplicate(n);
    cout << "single num: " << res;
    return 0;
}