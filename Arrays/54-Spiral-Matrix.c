/*
Problem: Spiral Matrix
LeetCode: 54
Topic: Matrix Traversal / Simulation
Time: O(m * n)
Space: O(m * n)
*/

/**
 * Note: The returned array must be malloced,
 * assume caller calls free().
 */
int* spiralOrder(int** matrix, int rowSize, int* ColSize, int* returnSize)
{
    int top = 0, bottom = rowSize - 1;
    int left = 0, right = *ColSize - 1;

    int *result = malloc(rowSize * (*ColSize) * sizeof(int));

    int index = 0;

    while(left <= right && top <= bottom)
    {
        // Left to right
        for(int i = left; i <= right; i++)
        {
            result[index++] = matrix[top][i];
        }

        top++;

        // Top to bottom
        for(int i = top; i <= bottom; i++)
        {
            result[index++] = matrix[i][right];
        }

        right--;

        // Right to left
        if(top <= bottom)
        {
            for(int i = right; i >= left; i--)
            {
                result[index++] = matrix[bottom][i];
            }

            bottom--;
        }

        // Bottom to top
        if(left <= right)
        {
            for(int i = bottom; i >= top; i--)
            {
                result[index++] = matrix[i][left];
            }

            left++;
        }
    }

    *returnSize = index;

    return result;
}