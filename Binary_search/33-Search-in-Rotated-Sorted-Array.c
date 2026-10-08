/*
Problem: Search in Rotated Sorted Array
LeetCode: 33
Topic: Binary Search / Rotated Sorted Array
Time: O(log n)
Space: O(1)
*/

int search(int* nums, int size, int target) {
    
    int left=0;
    int right=size-1;
    while(left<=right)
    {
        int mid=left+(right-left)/2;
        if(nums[mid]==target)
            {
                return mid;
            }
        if(nums[mid]>=nums[left])
        {
            
            if(target<nums[mid]&& nums[left]<=target)
            {
                right=mid-1;
            }
            else
            {
                left=mid+1;
            }
        }
        else
        {
           if(target>nums[mid]&&target<=nums[right])
           {
            left=mid+1;
           }
           else
           {
            right=mid-1;
           }

        }

    }
    return -1;
}