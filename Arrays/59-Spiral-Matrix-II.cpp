/*
Problem: Spiral Matrix II
LeetCode: 59
Topic: Matrix / Spiral Traversal
Time: O(n²)
Space: O(n²)
*/
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> result(n, vector<int>(n));

        int top = 0, bottom = n - 1;
        int left = 0, right = n - 1;
        int num = 1;

        while(left <= right && top <= bottom)
        {
            // Top row: left → right
            for(int i = left; i <= right; i++)
            {
                result[top][i] = num;
                num++;
            }
            top++;

            // Right column: top → bottom
            for(int i = top; i <= bottom; i++)
            {
                result[i][right] = num;
                num++;
            }
            right--;

            // Bottom row: right → left
            for(int i = right; i >= left; i--)
            {
                result[bottom][i] = num;
                num++;
            }
            bottom--;

            // Left column: bottom → top
            for(int i = bottom; i >= top; i--)
            {
                result[i][left] = num;
                num++;
            }
            left++;
        }

        return result;
    }
};