/*
Problem: Find Peak Element
LeetCode: 162
Topic: Binary Search
Time: O(log n)
Space: O(1)
*/
int findPeakElement(int* nums, int size) {
    int left =0;
    int right=size-1;
   
    while(left<right)
    {
        int mid=left+(right-left)/2;
        if(nums[mid]<nums[mid+1])
        {
         left=mid+1;
        }
        else
        {
            right=mid;
        }
    }
    return left;
}