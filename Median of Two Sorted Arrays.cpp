/*
4. Median of Two Sorted Arrays
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
The overall run time complexity should be O(log (m+n)).

Example 1:
Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.

Example 2:
Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5. 

Constraints:
nums1.length == m
nums2.length == n
0 <= m <= 1000
0 <= n <= 1000
1 <= m + n <= 2000
-106 <= nums1[i], nums2[i] <= 106
*/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
        if (nums1.size() > nums2.size()) 
        {
            return findMedianSortedArrays(nums2, nums1);
        }
        
        int x = nums1.size();
        int y = nums2.size();
        int low = 0; 
        int high = x;
        
        while (low <= high) 
        {
            int X = (low + high) / 2;
            int Y = (x + y + 1) / 2 - X;

            int maxX = INT_MIN;
            int maxY = INT_MIN;
            int minX = INT_MAX;
            int minY = INT_MAX;
            
            if (X > 0) 
            {
                maxX = nums1[X - 1];
            }
            if (X < x) 
            {
                minX = nums1[X];
            }
            if (Y > 0) 
            {
                maxY = nums2[Y - 1];
            }
            if (Y < y) 
            {
                minY = nums2[Y];
            }
            
            if (maxX <= minY && maxY <= minX) 
            {
                if ((x + y) % 2 == 0) 
                {
                    return (max(maxX, maxY) + min(minX, minY)) / 2.0;
                } 
                else 
                {
                    return max(maxX, maxY);
                }
            } 
            else if (maxX > minY) 
            {
                high = X - 1;
            } 
            else 
            {
                low = X + 1;
            }
        }       
        return -1.0; 
    }
};

