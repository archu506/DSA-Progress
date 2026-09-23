/*
Problem: Find the Duplicate Number
LeetCode: 287
Topic: Hashing / Set
Time: O(n)
Space: O(n)
*/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> seen;

        for(int n : nums)
        {
            if(seen.count(n) == 0)
            {
                seen.insert(n);
            }
            else
            {
                return n;
            }
        }

        return -1;
    }
};