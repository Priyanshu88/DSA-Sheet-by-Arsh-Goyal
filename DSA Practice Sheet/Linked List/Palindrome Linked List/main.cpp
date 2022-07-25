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
    bool isPalindrome(ListNode* head) {

        // creating a stack to store the linked list node value
        
        stack<ListNode*> stk;
        
        // then creating current pointed on head

        ListNode* curr = head;

        // traversing until it does not become null

        while(curr != NULL)
        {

            // pushing the node val into the stack

            stk.push(curr);

            // moving forward in current

            curr = curr->next;
        }

        // again assigning head to curr for comparision of palindrome

        curr = head;

        // traversing until curr does not becomes null and stack is not empty

        while(curr != NULL && !stk.empty())
        {

            // then comparing stack top value with the curr val
            // if it is not equal then return false

            if(stk.top()->val != curr->val)
                return false;

                // move curr on curr next

            curr = curr->next;

            // then pop the element

            stk.pop();
        }

        // if they match and stack becomes empty
        // then return true

        return true;

    }
};


// T.C.O(n)
// S.C.O(n)


// reversing the linked list from start till middle of linked list and then  simply match each element in 
// the first half and second half to determine if linked list is palindrome.


class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head, *fast = head, *prev = NULL, *temp;

        while(fast != NULL && fast->next != NULL)
        {
            fast = fast->next->next,
            tmp = slow->next, slow->next = prev, prev = slow, slow = tmp;

        }
        slow = (fast ? slow->next : slow);
        while(slow)
        {
            if(slow->val != prev->val) return false;
            else slow = slow->next, prev = prev->next;
        }
        return true;
    }
};


// T.C.O(n)
// S.C.O(1)



class Solution {
public:
    bool isPalindrome(ListNode* head) {

        // if head or head next is null return true

        if(head == NULL || head->next == NULL)
            return true;

            // declaring p1 and p2 as head and p3 as null 

            ListNode* p1 = head;
            ListNode* p2 = head;
            ListNode* p3 = NULL;

            // finding the middle element
            // while p2 and p2 next does not become null

            while(p2 != NULL && p2->next != NULL)
            {

                // move p1 by one node ahead

                p1 = p1->next;

                // and p2 by two node ahead

                p2 = p2->next->next;
            }

            // declaring tmp and prev pointer as null and curr pointing on head

            ListNode* tmp = NULL;
            ListNode* prev = NULL;
            ListNode* curr = head;

            // reversing the left part
            // traversing until curr does not become equal

            while(curr != p1)
            {
                
                // temp will move next to current

                tmp = curr->next;

                // and curr next will be prev

                curr->next = prev;

                // prev will be on curr

                prev = curr;
                
                // tmp will be on curr

                curr = tmp;
            }

            // connecting the last node of reversed left part with middle node

            head->next = p1;

            // if linked list has odd number nodes then we move p1 to the next

            if(p2 != NULL && p2->next == NULL)
            {
                p1 = p1->next;
            }

            // then we make point p3 pointer on prev

            p3 = prev;

            // traversing until right part does not become null i.e. p1 pointer is not null

            while(p1 != NULL)
            {

                // the value of p1 and p3 pointer do not match 
                // then return false

                if(p1->val != p3->val)
                {
                    return false;
                }

                // moving p1 to the next

                p1 = p1->next;

                // p3 to the next

                p3 = p3->next;
            }

            // if we reach null and nodes are matching then return true

            return true;

    }
};


// T.C.O(n)
// S.C.O(1)
