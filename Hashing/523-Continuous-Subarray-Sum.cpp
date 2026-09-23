/*
Problem: Continuous Subarray Sum
LeetCode: 523
Topic: Prefix Sum / Hashing
Time: O(n)
Space: O(n)
*/

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> first;

        // Remainder 0 exists before the array starts
        first[0] = -1;

        long long sum = 0;

        for(int right = 0; right < nums.size(); right++)
        {
            sum += nums[right];

            int remainder = sum % k;

            // First time seeing this remainder
            if(first.find(remainder) == first.end())
            {
                first[remainder] = right;
            }
            else
            {
                // Same remainder appeared before
                if(right - first[remainder] >= 2)
                {
                    return true;
                }
            }
        }

        return false;
    }
};