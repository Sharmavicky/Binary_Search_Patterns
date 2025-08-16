#include <iostream>
#include <vector>
using namespace std;

/*
    * We're given a sorted array of distinct integers and a target value, we have to find the index  of the target in the given array, if found than return it's index, otherwise return the index where it should be inserted in order to maintain the sorted order.

    * This code implements a binary search algorithm to find the index at which a target value should be inserted into a sorted array.

    * The time complexity of this algorithm is O(log n), where n is the number of elements in the array.

    * The space complexity is O(1) since it uses a constant amount of space.

*/

class Solution {
    public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1;

        while (left <= right) {
            int mid = (left+right) / 2;

            if (nums[mid] == target) { // target found, the return it's index
                return mid;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        // if target not found, return the insertion index
        return left;
    }
};

// main function for testing
int main() {
    vector<int> nums = {1, 3, 5, 6};
    int target = 8;

    int result = Solution().searchInsert(nums, target);
    cout << result;

    return 0;
}