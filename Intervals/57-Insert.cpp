/*
Problem: Insert Interval
LeetCode: 57
Topic: Intervals
Time: O(n)
Space: O(n)
*/

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newinter) {

        vector<vector<int>> result;

        int i = 0;

        // Add intervals before new interval
        while(i < intervals.size() &&
              intervals[i][1] < newinter[0])
        {
            result.push_back(intervals[i]);
            i++;
        }

        // Merge overlapping intervals
        while(i < intervals.size() &&
              intervals[i][0] <= newinter[1])
        {
            newinter[0] = min(intervals[i][0], newinter[0]);
            newinter[1] = max(intervals[i][1], newinter[1]);
            i++;
        }

        result.push_back(newinter);

        // Add remaining intervals
        while(i < intervals.size())
        {
            result.push_back(intervals[i]);
            i++;
        }

        return result;
    }
};