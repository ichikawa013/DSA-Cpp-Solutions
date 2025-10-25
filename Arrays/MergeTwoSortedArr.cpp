#include<bits/stdc++.h>
using namespace std;
//Space complexity : O(m+n)
//Time complexity : O(m+n)
// class Solution {
// public:
//     vector<int> merge(const vector<int>& nums1,const vector<int>& nums2){
//         vector<int> merged;
//         int m = nums1.size();
//         int n = nums2.size();

//         int  i = 0, j = 0;

//         while (i < m && j < n){
//             if (nums1[i] <= nums2[j]) {
//                 merged.push_back(nums1[i++]);
//             } else {
//                 merged.push_back(nums2[j++]);
//             }
//         } 
        
//         while (i < m) {
//             merged.push_back(nums1[i++]);
//         }
//         while (j < n) {
//             merged.push_back(nums2[j++]);
//         }

//         return merged;
//     }
//     double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
//         vector<int> result = merge(nums1, nums2);

//         int eles = result.size();
//         if (eles % 2 == 1)
//             return result[eles / 2];
//         return (result[eles / 2 - 1] + result[eles / 2]) / 2.0;
//     }
// };

//Space complexity : O(1)
//Time complexity : O(m+n)
// class Solution {
// public:
//     double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
//         int m = nums1.size();
//         int n = nums2.size();
//         int k = m + n;

//         int i = 0, j = 0;
//         int cnt = 0;
//         int ele1 = -1, ele2 = -1;
//         int flag1 = (n + m) / 2;
//         int flag2 = flag1 - 1;

//         while (i < m && j < n) {
//             if (nums1[i] <= nums2[j]) {
//                 if (cnt == flag1)
//                     ele1 = nums1[i];
//                 if (cnt == flag2)
//                     ele2 = nums1[i];
//                 cnt++;
//                 i++;
//             } else {
//                 if (cnt == flag1)
//                     ele1 = nums2[j];
//                 if (cnt == flag2)
//                     ele2 = nums2[j];
//                 cnt++;
//                 j++;
//             }
//         }

//         while (i < m) {
//             if (cnt == flag1)
//                 ele1 = nums1[i];
//             if (cnt == flag2)
//                 ele2 = nums1[i];
//             cnt++;
//             i++;
//         }
//         while (j < n) {
//             if (cnt == flag1)
//                 ele1 = nums2[j];
//             if (cnt == flag2)
//                 ele2 = nums2[j];
//             cnt++;
//             j++;
//         }

//         if ((n + m) % 2 == 1)
//             return ele1;

//         return (long double)(ele1 + ele2) / 2.0;
//     }
// };


//Time complexity : O(log(m+n))
//Space complexity : O(1)
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > nums2.size()) return findMedianSortedArrays(nums2, nums1);

        int m = nums1.size(), n = nums2.size();
        int total = m + n + 1;
        int low = 0, high = m;
        int half = total / 2;

        while (low <= high)
        {
            int mid_A = low + (high - low) / 2;
            int mid_B = half - mid_A;

            int A_L = (mid_A == 0) ? INT_MIN : nums1[mid_A - 1];
            int A_R = (mid_A == m) ? INT_MAX : nums1[mid_A];
            int B_L = (mid_B == 0) ? INT_MIN : nums2[mid_B - 1];
            int B_R = (mid_B == n) ? INT_MAX : nums2[mid_B];

            if (A_L <= B_R && B_L <= A_R)
            {
                if((m+n) % 2 == 1) return max(A_L,B_L);
                return (max(A_L,B_L) + min(A_R,B_R)) / 2.0;
            }
            else if (A_L > B_R) high = mid_A - 1;
            else low = mid_A + 1;
        }
        return 0.0;
    }
};