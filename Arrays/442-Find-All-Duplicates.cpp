/*
Problem: Find All Duplicates in an Array
LeetCode: 442
Topic: Hashing / Set
Time: O(n)
Space: O(n)
*/

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> arr;
        unordered_set<int> seen;

        for(int n : nums)
        {
            if(seen.count(n) == 0)
            {
                seen.insert(n);
            }
            else
            {
                arr.push_back(n);
            }
        }

        return arr;
    }
};