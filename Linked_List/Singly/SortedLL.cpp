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

ListNode* merge(ListNode *right, ListNode *left) {
    ListNode dummy;
    ListNode* temp = &dummy;
    while(right && left) {
        if(left->val > right->val) {
            temp->next = right;
            temp = right;
            right = right->next;
        } else {
            temp->next = left;
            temp = left;
            left = left->next;
        }
    }
    temp->next = left ? left : right;
    
    return dummy.next;
}

ListNode* sortList(ListNode* head) {
    
    if (!head || !head->next)
        return head;

    ListNode* right =head;
    ListNode* fast = head->next;
    ListNode* prev = nullptr;

    while (fast != nullptr && fast->next != nullptr) {
        prev = right;
        right = right->next;
        fast = fast->next->next;
    }

    prev->next = nullptr; 
    
    ListNode* leftSorted = sortList(head);
    ListNode* rightSorted = sortList(right);

    return merge(leftSorted, rightSorted);
}