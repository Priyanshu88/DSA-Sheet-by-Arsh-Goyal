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

// Initializing two pointers before and after. In the implementation we have initialized these two with a dummy ListNode.
// This helps to reduce the number of conditional checks we would need otherwise.
// You can try an implementation where you don't initialize with a dummy node and see it yourself!
// Iterate the original linked list, using the head pointer.
// If the node's value pointed by head is lesser than x, the node should be part of the before list.
// So we move it to before list.
// Else, the node should be part of after list. So we move it to after list.
// Once we are done with all the nodes in the original linked list, we would have two list before and after.
// The original list nodes are either part of before list or after list, depending on its value.
// Now, these two lists before and after can be combined to form the reformed list.

class Solution
{
public:
    ListNode *partition(ListNode *head, int x)
    {

        // before and after are the two pointers used to create the two list
        // before_head and after_head are used to save the heads of the two lists.
        // All of these are initialized with the dummy nodes created.

        ListNode *before_head = new ListNode(0);
        ListNode *before = before_head;
        ListNode *after_head = new ListNode(0);
        ListNode *after = after_head;
        while (head != NULL)
        {

            // If the original list node is lesser than the given x,
            // assigning it to the before list.

            if (head->val < x)
            {
                before->next = head;
                before = before->next;
            }

            // If the original list node is greater or equal to the given x,
            // assign it to the after list.

            else
            {
                after->next = head;
                after = after->next;
            }

            // move ahead in the original list

            head = head->next;
        }

        // Last node of "after" list would also be ending node of the reformed list so it's next will be assigned as null

        after->next = NULL;

        // Once all the nodes are correctly assigned to the two lists,
        // combining them to form a single list which would be returned.

        before->next = after_head->next;
        return before_head->next;
    }
};

// T.C.:O(n)
// S.C.:O(1)