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

    int getDecimalValue(ListNode* head) 
    {

        // initializing result as head value

        int result = head->val;

        // traversing until next of head reaches null
        
        while(head->next != NULL)
        {

            // 11101 = result = 1*2^0 -> (1*2^0)*2^1 + 1 -> (1*2^1 + 1)*2 +1 -> (1*2^2 + 1*2^1 + 1) * 2 + 0 -> (1*2^3 + 1*2^2 + 1*2^1 + 0)*2 + 1 -> (1*2^4 + 1*2^3 + 1*2^2 + 0*2^1) + 1 ==== 29
            // current value is head->next->val. Updating the result by shifting it by one to the left and adding the current value: result = result * 2 + head->next->val.

            result = result*2 + head->next->val;

            // moving head pointer to each element one by one

            head = head->next;
        }

        // returning result

        return result;
    }
};

// T.C. :O(n)
// S.C. :O(1)


class Solution {
public:
    int getDecimalValue(ListNode* head) 
    {
        int res = head->val;
        while(head != NULL)
        {   

            // The current value is head->next->val. Updating the result by shifting it by one to the 
            // left and adding the current value using logical OR: num = (num << 1) | head->next->val.


            res = (res << 1) | head->next->val;
            head = head->next;
        }
        return res;
    }
};


// T.C. :O(n)
// S.C. :O(1)
