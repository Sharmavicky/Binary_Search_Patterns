#include <iostream>
#include <vector>
using namespace std;

/*
    * We're given a 2D grid of integers where each row is sorted in non-increasing order, we have to count the number of negative numbers in the grid.

    * This code implements a binary search algorithm to count the negative numbers in each row of the grid.

    * The time complexity of this algorithm is O(m log n), where m is the number of rows and n is the number of columns in the grid.

    * The space complexity is O(1) since it uses a constant amount of space.
*/

class Solution {
    public:
    int countNegatives(vector<vector<int>>& grid) {
        int cnt = 0;
        
        for (int i=0; i<grid.size(); i++) {
            int left = 0, right = grid[i].size()-1;

            while (left <= right) {
                int mid = (left + right) / 2;

                if (grid[i][mid] < 0) {
                    // count all negative numbers from mid to right
                    cnt += (right - mid + 1);
                    right = mid - 1; // move left to find more negatives
                } else {
                    left = mid + 1; // move right to find negatives
                }
            }
        }

        return cnt;
    }
};

// main function
int main() {
    vector<vector<int>> grid = {
        {4, 3, 2, -1},
        {3, 2, 1, -1},
        {1, 1, -1, -2},
        {-1, -1, -2, -3}
    };

    int result = Solution().countNegatives(grid);
    cout << result << endl;

    return 0;
}