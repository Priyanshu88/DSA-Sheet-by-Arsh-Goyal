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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {

        // constructing stack s1 and s2

        stack<int> stk1;
        stack<int> stk2;

        while (l1 != NULL)
        {

            // pushing list1 elements

            stk1.push(l1->val);

            // moving to the next

            l1 = l1->next;
        }

        while (l2 != NULL)
        {

            // pushing list2 elements

            stk2.push(l2->val);

            // moving to the next

            l2 = l2->next;
        }

        // then initializing carry as 0 and newHead as null

        int carry = 0;
        ListNode *newHead = NULL;

        // traversing until both stacks od not become empty and carry not 0

        while (!stk1.empty() || !stk2.empty() || carry != 0)
        {

            int temp = 0;

            // if stack is empty assign 0 otherwise pop the element for both the cases

            if (!stk1.empty())
            {
                temp += stk1.top();
                stk1.pop();
            }

            if (!stk2.empty())
            {
                temp += stk2.top();
                stk2.pop();
            }

            // if temp is more than 10 taking its modulus creating new node

            ListNode *newNode = new ListNode(temp % 10);

            newNode->next = newHead->next;
            newHead->next = newNode;
            carry = temp / 10;
        }

        return newHead;
    }
};