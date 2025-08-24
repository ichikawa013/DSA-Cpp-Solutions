#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int merge(vector<int> arr, int low, int mid, int high)
    {
        int cnt;
        vector<int> temp;
        int left = low;
        int right = mid + 1;
        while (left <= mid && right <= high)
        {
            if (arr[left] <= arr[right])
            {
                temp.push_back(arr[left]);
                left++;
            }
            else
            {
                temp.push_back(arr[right]);
                cnt += mid - left + 1;
                right++;
            }
        }

        while (left <= mid)
        {
            temp.push_back(arr[left]);
            left++;
        }
        while (right <= high)
        {
            temp.push_back(arr[right]);
            left++;
        }

        for (int i = low; i <= high; i++)
        {
            arr[i] = temp[i - low];
        }

        return cnt;
    }

    int mergeSort(vector<int> arr, int low, int high)
    {
        int count;
        if (low >= high)
            return count;

        int mid = (low + high) / 2;
        count += mergeSort(arr, low, mid);
        count += mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);

        return count;
    }

    int numberOfInversions(vector<int> &a, int n)
    {
        return mergeSort(a, 0, n - 1);
    }
};