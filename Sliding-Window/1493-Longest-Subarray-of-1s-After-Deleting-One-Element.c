/*
Problem: Longest Subarray of 1's After Deleting One Element
LeetCode: 1493
Topic: Sliding Window
Time: O(n)
Space: O(1)
*/

int longestSubarray(int* nums, int size)
{
    int left = 0;
    int zerocnt = 0;
    int max = 0;

    for(int right = 0; right < size; right++)
    {
        if(nums[right] == 0)
        {
            zerocnt++;
        }

        while(zerocnt > 1)
        {
            if(nums[left] == 0)
            {
                zerocnt--;
            }

            left++;
        }

        int len = right - left;

        if(max < len)
        {
            max = len;
        }
    }

    return max;
}