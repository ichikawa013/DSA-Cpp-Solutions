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

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int sizeofLL(ListNode *head)
    {
        int cnt = 0;
        ListNode *mover = head;
        while (mover != nullptr)
        {
            cnt++;
            mover = mover->next;
        }
        return cnt;
    }

    ListNode* action(int k, ListNode *curr, ListNode* &node) {
        ListNode* prev = nullptr; 

        while (k--)
        {
            ListNode *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next; 
        }
        node = curr;
        return node;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || !head->next)
            return head;

        int cnt = sizeofLL(head);

        ListNode *prev = nullptr;
        ListNode *newHead = nullptr;
        ListNode *curr = head;

        while (cnt >= k)
        {
            ListNode* temp = nullptr;
            ListNode* groupHead = action(k, curr, temp);// temp is being passed in place of prev, which in next iteration will act as the logic in notebook and moves a pointer ahead of where it ended using node = curr; it gives us a head starting as in first iteration we had prev at nullptr
            if (!newHead) 
                newHead = groupHead;
            else {
                prev->next = groupHead;
            }            

            prev = curr;
            curr = temp;

            cnt -= k;
        }
        if (prev)
            prev->next = curr;

        return newHead;
    }
};