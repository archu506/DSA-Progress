/*
Problem: Remove Duplicates from Sorted Array II
LeetCode: 80
Topic: Two Pointers
Time: O(n)
Space: O(1)
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() <= 2)
            return nums.size();

        int k = 2;

        for(int i = 2; i < nums.size(); i++)
        {
            if(nums[i] != nums[k - 2])
            {
                nums[k] = nums[i];
                k++;
            }
        }

        return k;
    }
};