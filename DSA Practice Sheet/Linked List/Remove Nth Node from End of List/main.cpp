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
class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {

        // creating a new dummy node

        ListNode *start = new ListNode();

        // connecting the start next with the head node of linked list

        start->next = head;

        // making point slow and fast on start

        ListNode *slow = start;
        ListNode *fast = start;

        // traversing the list from head node to nth node from starting by moving fast pointer one step ahead

        for (int i = 1; i <= n;i++)
            fast = fast->next;

        // traversing until fast next does not become null
        
        while(fast->next != NULL)
        {

            // fast will move from nth index until fast next does not become null

            fast = fast->next;

            // slow will be moving one step ahead from starting and will point on nth node that has to be removed

            slow = slow->next;
        }

        // now slow next will be slow next next as we are detaching the link to remove th nth node

        slow->next = slow->next->next;

        // return head node as start next

        return start->next;
    }
};

// T.C.:O(n)
// S.C.:O(1)