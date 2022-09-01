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



#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *curr = head;
        for (int i = 0; i < k;i++)
        {
            if(curr == NULL)
                return head;
            curr = curr->next;
        }
        ListNode *curr = head;
        ListNode *prev = NULL;
        ListNode *next = NULL;
        for (int i = 0; i < k;i++)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head->next = reverseKGroup(curr, k);
        return prev;
    }
};


class Solution {
public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *before = dummy;
        ListNode *after = head;
        ListNode *curr = NULL;
        ListNode *prev = NULL;
        ListNode *next = NULL;
        while(true)
        {
            ListNode *cursor = after;
            for (int i = 0; i < k;i++)
            {
                if(cursor == NULL)
                    return dummy->next;
                cursor = cursor->next;
            }
            curr = after;
            prev = before;
            for (int i = 0; i < k;i++)
            {
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }
            after->next = curr;
            before->next = prev;
            before = after;
            after = curr;
        }


    }
};


class Solution {
public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {

        // if k is 1 means simply we need to rotate the element with itself so we return head or if head is null return head

        if(k==1 || head == NULL)
            return head;

        int count = k;

        // curr will point to head of each group

        ListNode *curr = head;

        while(curr != NULL && count != 0)
        {
            count--;
            curr = curr->next;
        }

        if(count > 0)
            return head;
        ListNode *prev = reverseKGroup(curr, k);
        ListNode *currHead = head;
        for (int i = 0; i < k;i++)
        {
            ListNode *next = currHead->next;
            currHead->next = prev;
            prev = currHead;
            currHead = next;

        }
        return prev;
    }
};

// T.C.: O(nk)
// S.C.: O(n/k)



