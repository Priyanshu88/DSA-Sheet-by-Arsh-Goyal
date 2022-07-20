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
    ListNode* middleNode(ListNode* head) 
    {
        
        // putting every node in an array

        vector<ListNode*> A={head};

        // traverse until A.back()->next does not become null

        while(A.back()->next != NULL)
        {

            // putting every element into the array

            A.push_back(A.back()->next);
        }

        // returning the middle node

        return A[A.size()/2];
    }
};



// T.C.:O(n)
// S.C.:O(n)






// When traversing the list with a pointer slow, 
// making another pointer fast that traverses twice as fast.
// When fast reaches the end of the list, slow must be in the middle.

class Solution {
public:
    ListNode* middleNode(ListNode* head) 
    {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != NULL & fast->next != NULL)
        {
            slow = head->next;
            fast = fast->next->next;

        }
        return slow;
    }
};


// T.C.:O(n)
// S.C.:O(1)