#include <bits/stdc++.h>
using namespace std;

struct Node
{
public:
    int data;
    Node *next;

    Node(int data1, Node *next1)
    {
        data = data1;
        next = next1;
    }

    Node(int data1) : data(data1), next(nullptr) {}
};

class Solution
{
public:
    Node *Array2LL(vector<int> arr)
    {
        Node *head = new Node(arr[0]);
        Node *mover = head;
        for (int i = 1; i < arr.size(); i++)
        {
            Node *temp = new Node(arr[i]);
            mover->next = temp;
            mover = temp;
        }
        return head;
    }

    Node *printLL(Node *head)
    {
        Node *mover = head;
        for (; mover != nullptr;)
        {
            cout << mover->data << '\n';
            mover = mover->next;
        }
        return head;
    }

    void deleteNode(Node *head)
    {
        int value;
        cout << "Enter the value to delete:" << " ";
        cin >> value;

        Node *mover = head;
        while (mover->data != value)
        {
            mover = mover->next;
        }

        mover->data = mover->next->data;
        mover->next = mover->next->next;
    }

    int sizeofLL(Node *head)
    {
        int cnt = 0;
        Node *mover = head;
        while (mover != nullptr)
        {
            cnt++;
            mover = mover->next;
        }
        return cnt;
    }

    int searchVal(Node *head)
    {
        int val, pos = 0;
        cout << "Enter value to search:" << " ";
        cin >> val;

        Node *mover = head;
        while (mover->data != val)
        {
            mover = mover->next;
            pos++;
        }

        return pos;
    }

    Node *reverseList(Node *head)
    {
        // stack<int> st;
        // ListNode* temp = head;
        // while (temp != nullptr)
        // {
        //     st.push(temp->val);
        //     temp = temp->next;
        // }
        // temp = head;
        // while (temp != nullptr)
        // {
        //     temp->val = st.top();
        //     st.pop();
        //     temp = temp->next;
        // }
        // return head;

        Node *prev = nullptr;
        Node *curr = head;

        while (curr != nullptr)
        {
            Node *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        return prev;
    }

    bool hasCycle(Node *head) {
        unordered_set<Node*> st;
        Node *mover = head;

        while (mover != nullptr)
        {
            if(st.find(mover) != st.end())
                return true;
            
            st.insert(mover);
            mover = mover->next;
        }
        
        return false;
    }
};

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    Solution sol;

    Node *head = sol.Array2LL(arr);
    Node *mover = head;

    sol.printLL(head);
    int numberNodes = sol.sizeofLL(head);
    cout << "num:" << numberNodes;
    int posIndex = sol.searchVal(head);
    cout << "pos: " << posIndex;
    return 1;
}