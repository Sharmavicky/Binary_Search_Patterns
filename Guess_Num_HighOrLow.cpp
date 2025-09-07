#include <iostream>
#include <vector>
#include <random>
using namespace std;

/*
    * Implements a simple guessing game using binary search.
    
    * - A hidden number (pickedNumber) is stored privately.
    * - The helper function guess(int n) simulates the LeetCode API:
    *      0  → correct guess
    *      1  → hidden number is higher
    *     -1  → hidden number is lower
    
    * - Public method guessNum(int num) tries to find the hidden number
    *   within the range [1..num] using binary search.
    
    * Time Complexity: O(log n)
    * Space Complexity: O(1)
*/

class Solution {
    private:
    int pickedNumber = 43;

    int guess(int n) {
        if (n == pickedNumber) return 0;
        else if (n < pickedNumber) return 1;
        else return -1;
    }

    public:
    int guessNum(int num) {
        int left = 1, right = num;

        while (left <= right) {
            int mid = (left + right) / 2;
            int g = guess(mid);

            if (g == 0) return mid;
            else if (g == 1) left = mid + 1;
            else right = mid - 1;
        }

        return -1;
    }
};

int main() {
    int num = 100;
    int result = Solution().guessNum(num);

    cout << result;
    return 0;
}