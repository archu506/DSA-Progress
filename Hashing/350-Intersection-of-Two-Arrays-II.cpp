/*
Problem: Intersection of Two Arrays II
LeetCode: 350
Topic: Hashing / Frequency Counting
Time: O(n + m)
Space: O(n)
*/
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int>result;
        unordered_map<int,int>seen;
        for(int n:nums1)
        {
          seen[n]++;
        }
        for(int n: nums2)
        {
           if(seen[n]>0)
           {
            seen[n]--;
            result.push_back(n);
           } 
        }
        return result;
    }
};