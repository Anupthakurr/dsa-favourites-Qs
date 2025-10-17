qs link ----->  https://leetcode.com/problems/median-of-two-sorted-arrays/description/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // Ensure nums1 is the smaller array
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }
        
        int x = nums1.size();
        int y = nums2.size();
        
        int low = 0, high = x;
        
        while (low <= high) {
            int partitionX = (low + high) / 2;
            int partitionY = (x + y + 1) / 2 - partitionX;
            
            int maxLeftX = (partitionX == 0) ? INT_MIN : nums1[partitionX - 1];
            int minRightX = (partitionX == x) ? INT_MAX : nums1[partitionX];
            
            int maxLeftY = (partitionY == 0) ? INT_MIN : nums2[partitionY - 1];
            int minRightY = (partitionY == y) ? INT_MAX : nums2[partitionY];
            
            if (maxLeftX <= minRightY && maxLeftY <= minRightX) {
                // Found correct partition
                if ((x + y) % 2 == 0) {
                    return (max(maxLeftX, maxLeftY) + min(minRightX, minRightY)) / 2.0;
                } else {
                    return max(maxLeftX, maxLeftY);
                }
            } else if (maxLeftX > minRightY) {
                high = partitionX - 1;
            } else {
                low = partitionX + 1;
            }
        }
        
        throw invalid_argument("Input arrays are not sorted.");
    }
};


//  my approach 

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getKthElement(vector<int>& a, vector<int>& b, int k) {
        int n = a.size(), m = b.size();
        int low = min(a.empty() ? INT_MAX : a.front(), b.empty() ? INT_MAX : b.front());
        int high = max(a.empty() ? INT_MIN : a.back(), b.empty() ? INT_MIN : b.back());

        // Binary search on value range, not index
        while (low <= high) {
            int mid = low + (high - low) / 2;

            // Count of numbers <= mid in both arrays
            int cnt = (int)(upper_bound(a.begin(), a.end(), mid) - a.begin())
                    + (int)(upper_bound(b.begin(), b.end(), mid) - b.begin());

            if (cnt <= k)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return low;
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int total = nums1.size() + nums2.size();

        if (total % 2 == 1)
            return getKthElement(nums1, nums2, total / 2);
        else {
            int left = getKthElement(nums1, nums2, total / 2 - 1);
            int right = getKthElement(nums1, nums2, total / 2);
            return (left + right) / 2.0;
        }
    }
};
