#include <iostream>
#include <vector>
using namespace std;

/*
    * Problem: Find the smallest letter in a sorted array of characters that is greater than a given target character.

    * The letters wrap around, meaning if the target is greater than or equal to the largest letter, the result should be the smallest letter.

    * Approach: Use binary search to find the position where the target would fit in the sorted array.
    
    * If the target is greater than or equal to the last letter, return the first letter.
*/

class Solution {
    public:
    char nextGreaterLetter(vector<char>& letters, char target) {
        int left = 0, right = letters.size()-1;

        while (left <= right) {
            int mid = (left + right) / 2;

            if (letters[mid] <= target) left = mid + 1;
            else right = mid - 1;
        }

        // If left is out of bounds, wrap around to the start of the array
        return letters[left % letters.size()]; 
    }
};

// main function 
int main() {
    vector<char> letters = {'c', 'f', 'j'};
    char target = 'e';

    char result = Solution().nextGreaterLetter(letters, target);
    cout << result << endl;

    return 0;
}