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
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;
        stack<int> stk;
        ListNode* curr = head;
        while(curr != NULL)
        {
            stk.push(curr->val);
            curr = curr->next;
        }
        curr = head;
        while(curr != NULL)
        {
            curr->val = stk.top();
            stk.pop();
            curr = curr->next;
        }
        return head;
        
    }
};



class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;
        ListNode* curr = head;
        ListNode* prev = NULL;
        while(curr != NULL)
        {
            ListNode* tmp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tmp;
        }
        return prev;
    }
};


class Solution {
    
    ListNode* newHead = NULL;
    
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;
        reverse(head);
        return newHead;
    }
    private:
    
    ListNode* reverse(ListNode* head)
    {
        if(head->next == NULL)
        {
            newHead = head;
            return head;
        }
        ListNode* tmp = reverse(head->next);
        tmp->next = head;
        head->next = NULL;
        return head;
    }
};


class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;
        return reverse(head, NULL);
    }
    
    public:
    ListNode* reverse(ListNode* head, ListNode* newHead)
    {
        if(head == NULL)
        {
            return newHead;
        }
        ListNode* next = head->next;
        head->next = newHead;
        return reverse(next, head);
    }
    
};
