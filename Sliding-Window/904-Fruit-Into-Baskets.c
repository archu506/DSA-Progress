/*
Problem: Fruit Into Baskets
LeetCode: 904
Topic: Sliding Window
Time: O(n)
Space: O(n)
*/

int totalFruit(int* fruits, int size)
{
    int freq[size];
    int types = 0, left = 0, max = 0;

    for(int i = 0; i < size; i++)
    {
        freq[i] = 0;
    }

    for(int right = 0; right < size; right++)
    {
        if(freq[fruits[right]] == 0)
        {
            types++;
        }

        freq[fruits[right]]++;

        while(types > 2)
        {
            freq[fruits[left]]--;

            if(freq[fruits[left]] == 0)
            {
                types--;
            }

            left++;
        }

        int len = right - left + 1;

        if(max < len)
        {
            max = len;
        }
    }

    return max;
}