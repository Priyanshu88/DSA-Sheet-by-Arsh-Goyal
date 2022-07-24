/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


// First we find the end node for the first linked list, then we connect the end node of 
// first linked list with the head node of second linked list. Now for finding the intersection, 
// we declare three pointers slow which wll move one step in list1, fast which will 
// move two step in list1 and start pointer pointing at NULL, we traverse the list with slow and 
// fast pointer and whenever we see that slow and fast are pointing on same node 
// then we point start pointer on the head of this list1 and we traverse the list again 
// with slow and start pointer until they point on same node, slow pointer will start from 
// where it was pointing earlier which is where fast pointer is pointing and 
// the start pointer will start from head of list1, when we see that slow pointer and start pointer 
// point on same node and we see that this is the beginning of the cycle so this is our answer. 
// At the end, we disconnect the end of list1 with head of list2 and assign next of endA as null 
// and return the start as this is our intersection point.



class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        // if lists are null return null
        
        if(headA == NULL || headB == NULL) return NULL;
        
        // finding the last node of list 1

        ListNode* endA = headA;
        while(endA->next != NULL)
        {
            endA = endA->next;
        }

        // connecting last node of list1 with head of list2

        endA->next = headB;
        ListNode* start = NULL;
        ListNode* slow = headA;
        ListNode* fast = headA;

        // moving slow and fast pointer until they point on same node

        while(fast != NULL && fast->next != NULL)
        {

            // slow is moving one step

            slow = slow->next;

            // fast is moving two step

            fast = fast->next->next;

            // if both are on same 

            if(slow == fast)
            {

                // pointing start on head of list1

                start = headA;

                // traversing until start and slow point on same by moving one step ahead to each pointer

                while(start != slow)
                {
                    start = start->next;
                    slow = slow->next;
                }
                break;
            }
        }

        // disconnecting the list1 end and head of list2

            endA->next = NULL;

            // returning start

            return start;
    }


};


// T.C.O(m+n)
// S.C.O(1)