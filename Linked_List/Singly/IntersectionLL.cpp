#include<bits/stdc++.h>
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* moverA = headA;
        ListNode* moverB = headB;

        while (moverA != moverB)
        {
            if(moverA == nullptr)
                moverA = headB;

            moverA = moverA->next;
            moverB = moverB->next;
        }
        
        return moverA;
    }
};