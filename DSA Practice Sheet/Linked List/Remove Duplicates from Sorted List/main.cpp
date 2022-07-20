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
    ListNode* deleteDuplicates(ListNode* head) 
    {

        // if there is an empty list or list with a single element (no duplicates)
        // then return head

        if(head == NULL || head->next == NULL) return head;

        // recursively calling the function to deleteDuplicates by head->next

        head->next = deleteDuplicates(head->next);
        
        // if head->val is same as the value of nest to head / If the value is same as previous elements value (compared during returning of function)
        // returning the unique value itself

        if(head->val == head->next->val) return head->next;
        
        //  if the value is different, return the previous element which will have next element as this unique value.
        
        else

        // return the unique value itself

        return head;


    }
};


// T.C.:O(n)
// S.C.:O(n)


class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) 
    {

        // creating curr node while traversing and assigning head to it

        ListNode* curr = head;

        // traversing it until we reach curr and curr next as NULL

        while (curr != NULL && curr->next != NULL)
        {

            // if curr value is same as curr next value

            if(curr->val == curr->next->val)
            {

                // assigning curr next to temp (a new created node)

                ListNode* temp = curr->next;

                // then linking curr next next to curr / assigning curr next next to curr next

                curr->next = curr->next->next;

                // now deleting the temp which is the duplicate stored in temp

                delete temp;
            }

            // else

            else
            {

                // moving to the next element assigning curr next in curr

                curr = curr->next;
            }
        }

        // retuning head 

        return head;
        
    }
};



// T.C.:O(n)
// S.C.:O(1)
