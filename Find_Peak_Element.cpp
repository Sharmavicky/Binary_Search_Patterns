#include <iostream>
#include <vector>
using namespace std;

/*
    * Solution class to find the peak index in a mountain array.
    * A mountain array is defined as an array where elements first strictly increase
    * and then strictly decrease. The peak is the maximum element in this array.

    * This class provides:
        * 1. A Binary Search based approach (O(log n)) to efficiently find the peak index.
        * 2. Uses the property of the mountain array to narrow the search range.
*/

class Solution {
    public:
    int binarySearchApproach(vector<int> &arr)
    {
        // taken left as 1 and right as length-2 bcz peak element cannot exist on both indices.
        int left = 1, right = arr.size() - 2;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;

            if (arr[mid - 1] < arr[mid] && arr[mid] > arr[mid + 1])
                return mid; // if arr[mid] > it' previous & next element
            else if (arr[mid - 1] < arr[mid])
                left = mid + 1; // if arr[mid] > it's previous element
            else
                right = mid - 1; // if arr[mid] > it's next element
        }
    }
};

// main function
int main() {
    vector<int> nums = {1, 3, 2};
    int result = Solution().binarySearchApproach(nums);
    cout << result;
    return 0;
}