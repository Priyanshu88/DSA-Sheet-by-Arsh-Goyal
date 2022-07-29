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

// Initializing current node to dummy head of the returning list.
// Initializing carry to 0, looping through lists l1 and l2 until you reach both ends and carry is 0
// Setting x to node l1's value if l1 has reached the end of l1, set to 0.
// Setting yy to node l2's value if l2 has reached the end of l2, set to 0.
// setting sum = x + y + carry
// Updating carry = sum / 10carry=sum/10.
// Creating a new node with the digit value of (sum % 10) and set it to current node's next, then advance current node to next advancing both l1 and l2.
// returning dummy head's next node.

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *dummyHead = new ListNode(0);
        ListNode *curr = demmyHead;
        int carry = 0;
        while (l1 != NULL || l2 != NULL || carry != 0)
        {
            int x = l1 ? l1->val : 0;
            int y = l2 ? l2->val : 0;
            int sum = carry + x + y;
            carry = sum / 10;
            curr->next = new ListNode(sum % 10);
            curr = curr->next;
            l1 = l1 ? l1->next : nullptr;
            l2 = l2 ? l2->next : nullptr;
        }
        return dummyHead->next;
    }
};

// T.C.O(n)
// S.C.O(n)