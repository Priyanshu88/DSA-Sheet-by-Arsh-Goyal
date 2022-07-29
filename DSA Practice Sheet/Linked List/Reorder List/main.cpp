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
    void reorderList(ListNode* head) {

        // if head or head next is null then return

        if(head == NULL || head->next == NULL)
            return;

        // creating stack for list

        stack<ListNode *> my_stack;

        // p1 pointer point on head

        ListNode *p1 = head;

        // assigning size as 0

        int size = 0;

        // traversing until does p1 not become null

        while (p1 != NULL)
        {   

            // pushing element into the stack

            my_stack.push(p1);

            // incrementing the size in each iteration

            size++;

            // and moving to the next element

            p1 = p1->next;

        }

        // p2 pointer points on head

        ListNode *p2 = head;

        // 

        for (int i = 0; i < size / 2;i++)
        {
            ListNode *Reorder = my_stack.top();
            my_stack.pop();
            Reorder->next = p2->next;
            p2->next = Reorder;
            p2 = p2->next->next;
        }

        p2->next = NULL;
    }
};