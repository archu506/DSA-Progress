/*
Problem: Find Minimum in Rotated Sorted Array
LeetCode: 153
Topic: Binary Search / Rotated Sorted Array
Time: O(log n)
Space: O(1)
*/
class Solution {
public:
    int findMin(vector<int>& nums) {
        int right=nums.size()-1;
        int left=0;
        
        
        while(left<right)
        {
            int mid=left+(right-left)/2;
            if(nums[mid]>nums[right])
            {
             left=mid+1;

            }
            else 
            {
                right=mid;
            }
        }
        return nums[left];
    }
};