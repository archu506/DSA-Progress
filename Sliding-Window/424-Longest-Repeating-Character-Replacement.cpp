
/*
Problem: Longest Repeating Character Replacement
LeetCode: 424
Topic: Sliding Window / Frequency Counting
Time: O(n)
Space: O(1)
*/

class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxfreq=0,left=0,ans=0;
        int freq[26]={0};
        for(int right=0;s[right]!='\0';right++)
        {
         freq[s[right]-'A']++;
         maxfreq=max(maxfreq,freq[s[right]-'A']);
         int windowsize=right-left+1;
         if(windowsize-maxfreq>k)
         {
            freq[s[left]-'A']--;
            left++;
         }
         else
         {
            ans=windowsize;
         }


        }
       return ans;

    }
};