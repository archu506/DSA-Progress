/*
Problem: Group Anagrams
LeetCode: 49
Topic: Hashing / Sorting
Time: O(n * k log k)
Space: O(n * k)
*/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        unordered_map<string, vector<string>> mp;

        for(const string& word : strs)
        {
            string key = word;
            sort(key.begin(), key.end());

            mp[key].push_back(word);
        }

        vector<vector<string>> result;

        for(auto& group : mp)
        {
            result.push_back(group.second);
        }

        return result;
    }
};