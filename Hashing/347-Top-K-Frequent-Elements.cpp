/*
Problem: Top K Frequent Elements
LeetCode: 347
Topic: Hashing / Sorting
Time: O(n + m log m)
Space: O(m)
*/
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
       unordered_map<int, int>freq;
       vector<int>result;
        vector<pair<int, int>> arr;
       for(int n:nums)
       {
        freq[n]++;
       } 
       
       for(const auto& n:freq)
       {
        
        arr.push_back(n);
       }
       
       sort(arr.begin(), arr.end(), [](auto a, auto b)
       {
        return a.second>b.second;
       });
      int i=0;
       while(k>0)
       {
        result.push_back(arr[i].first);

        k--;
        i++;
       }
       return result;
    }
};