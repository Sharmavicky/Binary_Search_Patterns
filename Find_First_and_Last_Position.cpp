#include <iostream>
#include <vector>
using namespace std;

/*
    * Function: BruteForce
    * --------------------
    * Finds the first and last position of a target element in a sorted array.
    * If the target is not found, returns {-1, -1}.

    * Approach:
    *  - Perform a binary search to locate one occurrence of the target.
    *  - Once found, expand left and right from that index to capture the first and last occurrence of the target.
    *  - Return the indices as a vector [firstIndex, lastIndex].

    * Example:
    *   Input:  nums = [5, 7, 7, 8, 8, 10], target = 8
    *   Output: [3, 4]

    * Time Complexity:
    *   - Binary search step: O(log n)
    *   - Expanding left and right to count occurrences: O(k), where k = number of occurrences of target
    *   - Worst case (all elements are target): O(n)

    * Space Complexity:
    *   - O(1), since only a few variables and a fixed-size result array are used.
*/


class Solution {
    public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int length = nums.size(), left=0, right=length-1;
        vector<int> resultArr = {-1, -1};

        while (left <= right) {
            int mid = (left + right) / 2;

            if (nums[mid] == target) {
                left = mid - 1;
                right = mid + 1;
                resultArr[0] = mid;
                resultArr[1] = mid;

                // loop towards left from the mid to find first occurrence 
                while (left >= 0 && nums[left] == target) {
                    resultArr[0] = left;
                    left--;
                }

                // loop towards right from the mid to find last occurrence
                while (right <= length-1 && nums[right] == target) {
                    resultArr[1] = right;
                    right++;
                }
                // break the outer loop one you found the range
                break;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        // return the range array
        return resultArr;
    }
};

// main function 
int main() {
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    int target = 8;

    vector<int> result = Solution().searchRange(nums, target);

    for (int n: result) {
        cout << n << " ";
    }
    cout << endl;

    return 0;
}