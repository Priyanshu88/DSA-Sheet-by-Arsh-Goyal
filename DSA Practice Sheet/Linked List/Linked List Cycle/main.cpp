/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {

        // if the linked list is empty or next node of head is null
        // return false

        if(head == NULL || head->next == NULL)
            return false;

        // declaring two pinter p1(slow) and p2(fast) at first and second node respectively 

        ListNode* p1 = head;
        ListNode* p2 = head->next;

        // keep running the loop until p1 and p2 points on the same node element

        while(p1 != p2) 
        {

            // if p2 is null and p2->next is null then return false as there is no cycle in linked list

            if(p2 == NULL || p2->next == NULL) return false;

            // moving p1 pointer slowly (to the next node) and p2 pointer fastly (next to next node)

            p1 = p1->next;
            p2 = p2->next->next;
        }
        
        // if they are at same node 
        // return true

        return true;

    }
};



// T.C. :O(n)
// S.C. :O(1)