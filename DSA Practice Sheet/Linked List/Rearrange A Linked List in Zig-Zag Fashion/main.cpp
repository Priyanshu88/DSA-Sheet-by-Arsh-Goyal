/*
The structure of linked list is the following
struct Node
{
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    Node *zigZag(Node *head)
    {

        // If flag is true, then next node should be greater in the desired output.

        bool flag = true;
        Node *curr = head;
        while (curr->next)
        {
            if (flag)
            {

                // If we have a situation like A > B > C where
                // A, B and C are consecutive Nodes in list we
                // get A > B < C by swapping B and C

                if (curr->data > curr->next->data)
                {
                    swap(curr->data, curr->next->data);
                }
            }
            else
            {

                // If we have a situation like A < B < C where
                // A, B and C  are consecutive Nodes in list we
                // get A < C > B by swapping B and C

                if (curr->data < curr->next->data)
                {
                    swap(curr->data, curr->next->data);
                }
            }

            /* flip flag for reverse checking */

            flag = !flag;
            curr = curr->next;
        }
        return head;
    }
};

// T.C. O(n)
// S.C. O(1)