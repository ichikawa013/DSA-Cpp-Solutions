#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int kthElement(vector<int> &a, vector<int> &b, int k)
    {
        if (a.size() > b.size())
            return kthElement(b, a, k);

        int m = a.size();
        int n = b.size();
        
        int total = m + n + 1;
        int low = max(0, k - n), high = min(k, m);
        int half = total / 2;

        while (low <= high)
        {
            int mid_A = low + (high - low) / 2;
            int mid_B = k - mid_A;

            int A_L = (mid_A == 0) ? INT_MIN : a[mid_A - 1];
            int A_R = (mid_A == m) ? INT_MAX : a[mid_A];
            int B_L = (mid_B == 0) ? INT_MIN : b[mid_B - 1];
            int B_R = (mid_B == n) ? INT_MAX : b[mid_B];

            if (A_L <= B_R && B_L <= A_R)
            {
                return max(A_L, B_L);
            }
            else if (A_L > B_R)
                high = mid_A - 1;
            else
                low = mid_A + 1;
        }
        return -1;
    }
};