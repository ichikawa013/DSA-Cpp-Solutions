#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// class Solution
// {
// public:
//     bool isPalindrome(ListNode *head)
//     {
//         vector<int> vals;
//         ListNode *mover = head;
//         while (mover != nullptr)
//         {
//             vals.push_back(mover->val);
//             mover = mover->next;
//         }
//         int left = 0;
//         int right = vals.size() - 1;

//         while (left < right)
//         {
//             if (vals[left] != vals[right])
//                 return false;
//             left++;
//             right--;
//         }
//         return true;
//     }
// };

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode *reverseList(ListNode *head) {
        ListNode *prev = nullptr;
        ListNode *curr = head;

        while (curr != nullptr)
        {
            ListNode *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        return prev;
    }

    bool isPalindrome(ListNode* head) {
        ListNode *middle = middleNode(head);
        ListNode* reverseHead = reverseList(middle);

        ListNode *left = head;
        ListNode *right = reverseHead;

        while(right != nullptr) {
            if(left->val != right->val)
                return false;

            left = left->next;
            right = right->next;
        }

        return true;
    }
};