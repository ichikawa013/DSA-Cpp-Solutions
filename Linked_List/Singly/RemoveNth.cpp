#include <bits/stdc++.h>
using namespace std;

struct ListNode {
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

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int cnt = sizeofLL(head);

        if(n > cnt) return head;

        if(n == cnt) return head->next;
         
        ListNode *mover = head;
        while(cnt != n+1) {///here we go to node just before the nth node from back
            mover = mover->next;
            cnt--;
        }

        mover->next = mover->next->next; 
        return head;
    }
};