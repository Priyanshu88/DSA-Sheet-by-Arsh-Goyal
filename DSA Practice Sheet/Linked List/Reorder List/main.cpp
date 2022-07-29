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
    void reorderList(ListNode *head)
    {

        // if head or head next is null then return

        if (head == NULL || head->next == NULL)
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

        // between every two nodes inserting the one in the top of the stack

        for (int i = 0; i < size / 2; i++)
        {

            // here assigning top element of stack to reorder

            ListNode *Reorder = my_stack.top();

            // poping the element then

            my_stack.pop();

            // linking the reorder next with p2 next

            Reorder->next = p2->next;

            // and p2 next with reorder

            p2->next = Reorder;

            // moving p2 for two step because have to insert in between next two nodes

            p2 = p2->next->next;
        }

        // if we reach the end assigning p2 next as null

        p2->next = NULL;
    }
};

class Solution
{
public:
    void reorderList(ListNode *head)
    {

        // assigning  head to curr

        ListNode *curr = head;

        // create a list vector ans

        vector<ListNode *> ans;

        // traversing until curr does not become null

        while (curr != NULL)
        {

            // pushing curr element into the stack

            ans.push_back(curr);

            // moving curr ahead

            curr = curr->next;
        }

        // initializing start as 0 end as size-1

        int start = 0;
        int end = ans.size() - 1;

        // traversing until start and end becomes equal

        while (start < end)
        {

            // start index of ans vector next will be end index list node

            ans[start]->next = ans[end];

            // end index node next will be at start + 1 index

            ans[end]->next = ans[start + 1];

            // incrementing start

            start++;

            // decrementing end

            end--;
        }

        // lastly start index ans next will be null

        ans[start]->next = NULL;
    }
};