/*
Problem: Search in Rotated Sorted Array II
LeetCode: 81
Topic: Binary Search / Rotated Sorted Array
Time: O(log n) average, O(n) worst case
Space: O(1)
*/
bool search(int* nums, int size, int target) {

    int left = 0;
    int right = size - 1;

    while (left <= right) {

        int mid = left + (right - left) / 2;

        // Target found
        if (nums[mid] == target) {
            return true;
        }

        // Cannot determine the sorted half
        if (nums[left] == nums[mid] &&
            nums[mid] == nums[right]) {

            left++;
            right--;
        }

        // Left half is sorted
        else if (nums[left] <= nums[mid]) {

            if (nums[left] <= target &&
                target < nums[mid]) {

                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }

        // Right half is sorted
        else {

            if (nums[mid] < target &&
                target <= nums[right]) {

                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
    }

    return false;
}