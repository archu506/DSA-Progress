/*
Problem: Koko Eating Bananas
LeetCode: 875
Topic: Binary Search on Answer
Time: O(n log m)
Space: O(1)
*/

int minEatingSpeed(int* piles, int size, int h) {
    
    int left=1;
    int right=0;
   

    for(int i=0;i<size;i++)
    {
        if(piles[i]>right)
        {
            right=piles[i];
        }
    }
    while(left<right)
    {
        int mid=left+(right-left)/2;
          long long hrs=0;
        for(int i=0;i<size;i++)
        {
            hrs+=(piles[i]+mid-1)/mid;
        }
        if(hrs<=h)
        {
         right=mid;
        }
        else
        {
            left=mid+1;
        }
        
    }
    return left;
}