/*
Problem: K Radius Subarray Averages
LeetCode: 2090
Topic: Sliding Window
Time: O(n)
Space: O(n)
*/

/**
 * Note: The returned array must be malloced,
 * assume caller calls free().
 */
int* getAverages(int* nums, int size, int k, int* returnSize)
{
    long long sum = 0;

    int *avg = malloc(size * sizeof(int));

    *returnSize = size;

    for(int i = 0; i < size; i++)
    {
        avg[i] = -1;
    }

    int windowsize = 2 * k + 1;

    if(windowsize > size)
    {
        return avg;
    }

    for(int i = 0; i < windowsize; i++)
    {
        sum += nums[i];
    }

    int center = k;

    avg[center] = sum / windowsize;

    for(int i = windowsize; i < size; i++)
    {
        sum -= nums[i - windowsize];
        sum += nums[i];

        center++;

        avg[center] = sum / windowsize;
    }

    return avg;
}