#include <bits/stdc++.h>
using namespace std;

/*
    * Class Name: SnapshotArray
    *
    * Description:
    * -------------
    * Implements a snapshot-based array that supports versioning through set, snap, and get operations.
    *
    * Features:
    * ----------
    * 1. set(index, val) — Sets the element at the specified index.
    * 2. snap() — Takes a snapshot and returns its snapshot ID.
    * 3. get(index, snap_id) — Retrieves the value at an index for a given snapshot.
    *
    * Approach:
    * ----------
    * - Each index stores a history of (snap_id, value) pairs.
    * - Binary search is used during `get()` to efficiently find the latest applicable value.
    *
    * Time Complexity:
    * ----------------
    * set()  → O(1)
    * snap() → O(1)
    * get()  → O(log n) per query
    *
    * Space Complexity:
    * -----------------
    * O(n * m) where m = number of snapshots that modified a given index.
*/

class SnapshotArray {
private:
    int snap_id;
    vector<vector<pair<int, int>>> history;

public:
    SnapshotArray(int length) {
        snap_id = 0;
        history.resize(length);
        
        for (int i=0; i<length; i++) {
            history[i].push_back({0, 0});
        }
    }

    void set(int idx, int val) {
        if (history[idx].back().first == snap_id) history[idx].back().second = val;
        else history[idx].push_back({snap_id, val});
    }

    int snap() {
        return snap_id++;
    }

    int get(int index, int id) {
        auto &arr = history[index];
        int left = 0, right = arr.size() - 1;
        int res = 0;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid].first <= id) {
                res = arr[mid].second;
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return res;
    }
};