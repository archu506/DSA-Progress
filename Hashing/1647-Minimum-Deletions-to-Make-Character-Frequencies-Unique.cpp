/*
Problem: Minimum Deletions to Make Character Frequencies Unique
LeetCode: 1647
Topic: Frequency Counting / Hashing
Time: O(n)
Space: O(1)
*/

class Solution {
public:
    int minDeletions(string s) {
        int freq[26] = {0};
        int del_cnt = 0;
        unordered_set<int> seen;

        for(int i = 0; s[i] != '\0'; i++)
        {
            freq[s[i] - 'a']++;
        }

        for(int i = 0; i < 26; i++)
        {
            while(freq[i] > 0 && seen.count(freq[i]))
            {
                freq[i]--;
                del_cnt++;
            }

            if(freq[i] > 0)
            {
                seen.insert(freq[i]);
            }
        }

        return del_cnt;
    }
};
