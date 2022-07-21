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
    ListNode* removeElements(ListNode* head, int val) 
    {

        // if head is null return head

        if(head == NULL) return head;

        // initializing two pointers pre as null and curr as head

        ListNode* prev = NULL;
        ListNode* curr = head;

        // traverse until curr becomes null

        while (curr != NULL)

        {

            // if curr value is equal to value

            if(curr->val == val)
            {

                // also prev is null then curr next will be the head

                if(prev == NULL) head = curr->next;

                // else curr next will be the prev next

                else prev->next = curr->next;
            }

            // // if curr value is not equal to value

            else

                // then prev will be now on current

                prev = curr;

                // and curr will move to the next of current in each step 
            
            curr = curr->next;
        }

        // and return the head
        
        return head;
    }
};



// T.C.:O(n)
// S.C. :O(1)



// recursive approach

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) 
    {

        // if head is null return head

        if(head == NULL) return head;
        
        // recursively calling the function to removeElements if it has the value val from second node to last node 

        ListNode* h = removeElements(head->next, val);
        
        // if head value is equal to val removing the head the first node looking from second till the last node and
        // removing all the values with val then in this case return h
        
        if(head->val == val) return h;

        // otherwise if head is unmodified then it's next will be head returned by the h function call

        head->next = h;

        // and return head

        return head;
    }
};


// T.C.:O(n)
// S.C. :O(n)
