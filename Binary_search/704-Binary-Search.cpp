/*
Problem: Binary Search
LeetCode: 704
Topic: Binary Search
Time: O(log n)
Space: O(1)
*/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left=0, right=nums.size()-1;
        
        while(left<=right)
        {

            int mid=left+(right-left)/2;
         if(nums[mid]==target)
         {
            return mid;
         }
         else if(nums[mid]<target)
         {
           left=mid+1;
         }
         else
         {
            right=mid-1;
         }
        }
        return -1;
    }
};