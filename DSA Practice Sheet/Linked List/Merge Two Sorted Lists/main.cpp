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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) 
    {

        // if list1 is null then return list2
        
        if(list1 == NULL) return list2;
        
        // if list2 is null return list1

        if(list2 == NULL) return list1;

        // if list1 value is less than or equal to the list2 value pointer

        if(list1->val <= list2->val)
        {
            
            // then recursively calling for list1 next and whole list2 for next of list1 and store in it

            list1->next = mergeTwoLists(list1->next, list2);
            
            // returning list1

            return list1;
        }

        // if list2 value is less than the list1 value pointer

        else
        {

        // then recursively calling for whole list1 and list2 next for next of list2 and store in it

            list2->next = mergeTwoLists(list1, list2->next);
            
            // returning list2

            return list2;
        }
    }
};


// T.C.:O(n)
// S.C. :O(n)



class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) 
    {

        // if list1 is null return list2

        if(list1 == NULL) return list2;

        // if list2 is null return list1

        if(list2 == NULL) return list1;

        // creating dummy nodes for merging purpose

        ListNode* head = NULL;
        ListNode* tail = NULL;

        // if value of list1 is less than or equal to the list2 value
        
        if(list1->val <= list2->val)
        {

            // point head and tail pointer at list1

            head = tail = list1;

            // and moving forward in list1 until list1 value is less than or equal to list2

            list1 = list1->next;
        }

        // if value of list2 is less than or equal to the list1 value

        else
        {

            // point head and tail pointer at list2

            head = tail = list2;

            // and moving forward in list3 until list2 value is less than list1


            list2 = list2->next;
        }

        // iterating until list1 and list2 becomes null

        while(list1 != NULL && list2 != NULL)
        {
            
            // if list1 value is less than or equal to the list2 value

            if(list1->val <= list2->val)
            {

                // then tail nest will list1
                // and tail will point on lis11 and 
                // list1 will move to list1 next

                tail->next = list1;
                tail = list1;
                list1 = list1->next;
            }

            // if list2 value is less than or equal to the list1 value

            else
            {

                // then tail next will be list2
                // tail will point on list1 and
                // list2 will move to list2 next

                tail->next = list2;
                tail = list2;
                list2 = list2->next;
            }

        }

        // if list1 has reached to end then 
        // tail next will be list2

        if(list1 == NULL) tail->next = list2;
        
        // otherwise if list2 has reached to end then 
        // tail next will be list1

        else tail->next = list1;

    // returning head

    return head;


    }
};


// T.C.:O(n+n)
// S.C. :O(1)