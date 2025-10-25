#include<bits/stdc++.h>
using namespace std;

//linear search approach
// class Solution {
//   public:
//     int validation(vector<int> &arr, int pages) {
//         int std = 1, pagesStd = 0;
//         for (auto ele : arr)
//         {
//             if(pagesStd + ele <= pages) pagesStd += ele;
//             else{
//                 pagesStd = ele;
//                 std++;
//             }
//         }
//         return std;
//     }
//     int findPages(vector<int> &arr, int k) {
//         // code here
//         int low = *max_element(arr.begin(),arr.end());
//         int high = accumulate(arr.begin(), arr.end(), 0);
//         int ans = -1;

//         if(arr.size() < k) return -1;
//         for (int pages = low; pages <= high; pages++) {
//             int countStd = validation(arr, pages);
//             if(countStd <= k) {
//                 ans = pages;
//                 return pages;
//                 break; 
//             }
//         }
//         return ans;
//     }
// };

//optimized of O(logn) + n 

class Solution {
  public:
    int validation(vector<int> &arr, int pages) {
        int std = 1, pagesStd = 0;
        for (auto ele : arr)
        {
            if(pagesStd + ele <= pages) pagesStd += ele;
            else{
                pagesStd = ele;
                std++;
            }
        }
        return std;
    }
    int findPages(vector<int> &arr, int k) {
        // code here
        int low = *max_element(arr.begin(),arr.end());
        int high = accumulate(arr.begin(), arr.end(), 0);
        int ans = -1;

        if(arr.size() < k) return -1;
        while(low <= high) {
            int pages = low + (high - low)/2;
            int countStd = validation(arr, pages);
            if(countStd <= k) {
                ans = pages;
                high = pages - 1;
            }
            else low = pages + 1;
        }
        return ans;
    }
};