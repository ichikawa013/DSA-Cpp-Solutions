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
    
    ListNode *reverseList(ListNode *head)
    {
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

    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0)
            return head;

        int cnt = sizeofLL(head);   
        k = k % cnt;
        if(k == 0) return head;
        int k1 = k-1;

        ListNode* newHead = reverseList(head);// reverse whole
        ListNode* mover = newHead;
        while(k1--) {
            mover = mover->next;
        }
        ListNode* part2Head = mover->next;
        mover->next = nullptr;
        newHead = reverseList(newHead);//after reversing the left half

        
        ListNode* secondHalfHead = reverseList(part2Head);
        mover = newHead;
        while(mover->next != nullptr) {
            mover = mover->next;
        }
        mover->next = secondHalfHead;
        
        return newHead;
    }
};