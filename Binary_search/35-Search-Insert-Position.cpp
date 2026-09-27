/*
Problem: Search Insert Position
LeetCode: 35
Topic: Binary Search
Time: O(log n)
Space: O(1)
*/
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left=0, right=nums.size()-1;
                while(left<=right)
                {
                    int mid=(left+right)/2;
                    if(nums[mid]==target)
                    {
                        return mid;
                    }
                    else if(target>nums[mid])
                    {
                     left=mid+1;
                    }
                    else
                    {
                       right=mid-1; 
                    }
                }
                return left;
    }
};