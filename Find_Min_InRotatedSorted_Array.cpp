#include <iostream>
#include <vector>
using namespace std;

/*
    * Provides a method to find the minimum element in a rotated sorted array.
    
    * Method: findMin
    * ---------------
    * Uses a modified binary search approach:
    *   - If the current subarray [left..right] is already sorted,
    *     the leftmost element is the minimum for that range.
    *   - If the left half is sorted, discard it and search in the right half.
    *   - Otherwise, discard the right half and search in the left half.
    
    * Time Complexity: O(log n)
    * Space Complexity: O(1)
*/


class Solution {
    public:
    int findMIn(vector<int>& nums) {
        int length = nums.size();
        int left = 0, right = length - 1;
        int minimum = INT32_MAX;

        if (length == 1) return nums[0];

        while (left <= right) {
            int mid = (left + right) / 2;

            if (nums[left] <= nums[right]) {
                minimum = min(minimum, nums[left]);
                break;
            }

            if (nums[left] <= nums[mid]) {
                minimum = min(minimum, nums[left]);
                left = mid + 1;
            } else {
                minimum = min(minimum, nums[mid]);
                right = mid - 1;
            }
        }

        return minimum;
    }
};

// main function
int main() {
    vector<int> nums = {2, 3, 4, 5, 1};
    int result = Solution().findMIn(nums);
    cout << result;

    return 0;
}