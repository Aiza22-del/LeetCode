/*
34. Find First and Last Position of Element in Sorted Array
Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.
If target is not found in the array, return [-1, -1].
You must write an algorithm with O(log n) runtime complexity.

Example 1:
Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]

Example 2:
Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]

Example 3:
Input: nums = [], target = 0
Output: [-1,-1]

Constraints:
0 <= nums.length <= 105
-109 <= nums[i] <= 109
nums is a non-decreasing array.
-109 <= target <= 109
*/

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) 
    {
        vector<int> result(2, -1);
        result[0] = findLeft(nums, target);
        result[1] = findRight(nums, target);
        return result;
    }

private:
    int findLeft(vector<int>& nums, int target) 
    {
        int left = 0;
        int right = nums.size() - 1;
        int index = -1;

        while (left <= right) 
        {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) 
            {
                index = mid;
                right = mid - 1;
            } 
            else if (nums[mid] < target) 
            {
                left = mid + 1;
            } 
            else 
            {
                right = mid - 1;
            }
        }
        return index;
    }

    int findRight(vector<int>& nums, int target) 
    {
        int left = 0;
        int right = nums.size() - 1;
        int index = -1;

        while (left <= right) 
        {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) 
            {
                index = mid;
                left = mid + 1;
            } 
            else if (nums[mid] < target) 
            {
                left = mid + 1;
            } 
            else 
            {
                right = mid - 1;
            }
        }
        return index;
    }
};

