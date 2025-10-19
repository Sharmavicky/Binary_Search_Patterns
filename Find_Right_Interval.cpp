#include <bits/stdc++.h>
using namespace std;

/*
    * Class Name: Solution
    *
    * Description:
    * -------------
    * This class implements two approaches to solve the "Find Right Interval" problem.
    *
    * Problem Statement:
    * ------------------
    * Given a list of intervals, for each interval i, find the index of another interval j
    * such that:
    *     - intervals[j].start >= intervals[i].end
    *     - and intervals[j] has the smallest possible start value among all that satisfy the above condition.
    * If no such interval exists, return -1 for that interval.
    *
    * Implemented Approaches:
    * -----------------------
    * 1. LinearSearch (Brute-Force):
    *      - For each interval i, iterate over all other intervals j.
    *      - Track the interval with the smallest start value satisfying start_j >= end_i.
    *      - Time Complexity: O(n²)
    *      - Space Complexity: O(n)
    *
    * 2. BinarySearch (Optimized):
    *      - Store each interval’s start along with its original index.
    *      - Sort the list of starts.
    *      - For each interval i, perform binary search to find the smallest start >= end_i.
    *      - Retrieve and store the corresponding original index.
    *      - Time Complexity: O(n log n)
    *      - Space Complexity: O(n)
    *
    * Notes:
    * ------
    * - Both methods return a vector of size n, where each element represents
    *   the index of the "right" interval for the corresponding interval.
    * - The BinarySearch method is significantly faster and preferred for large inputs.
*/

class Solution {
    public:
    vector<int> LinearSearch(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<int> res(n, 0);

        for (int i = 0; i < n; i++) {
            int end_i = intervals[i][1]; // end of 'i'
            int min_start = INT_MAX;
            int min_idx = -1;

            for (int j = 0; j < n; j++) {
                int start_j = intervals[j][0];
                if (i != j) {
                    if(start_j >= end_i && start_j < min_start) {
                        min_start = start_j;
                        min_idx = j;
                    }
                }
            }

            res[i] = min_idx;
        }

        return res;
    }

    vector<int> BinarySearch(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<pair<int, int>> start_idx; // {start_idx[i], i}
        vector<int> res(n, -1);

        for (int i=0; i<n; i++) start_idx.push_back({intervals[i][0], i});
        
        // sort start_idx
        sort(start_idx.begin(), start_idx.end());

        for (int i = 0; i < n; i++) {
            int end_i = intervals[i][1];

            int left = 0, right = n-1, ans = -1;

            while (left <= right) {
                int mid = left + (right - left) / 2;

                if (start_idx[mid].first >= end_i) {
                    ans = start_idx[mid].second;
                    right = mid - 1;
                } else {
                    left =  mid + 1;
                }
            }

            res[i] = ans;
        }

        return res;
    }
};