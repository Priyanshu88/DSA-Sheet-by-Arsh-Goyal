// 23. Merge k Sorted Lists

// You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

// Merge all the linked-lists into one sorted linked-list and return it.



// Example 1:

// Input: lists = [[1,4,5],[1,3,4],[2,6]]
// Output: [1,1,2,3,4,4,5,6]
// Explanation: The linked-lists are:
// [
//   1->4->5,
//   1->3->4,
//   2->6
// ]
// merging them into one sorted list:
// 1->1->2->3->4->4->5->6
// Example 2:

// Input: lists = []
// Output: []
// Example 3:

// Input: lists = [[]]
// Output: []


// Constraints:

// k == lists.length
// 0 <= k <= 104
// 0 <= lists[i].length <= 500
// -104 <= lists[i][j] <= 104
// lists[i] is sorted in ascending order.
// The sum of lists[i].length will not exceed 104


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
    ListNode* merge2Lists(ListNode* l1, ListNode* l2)
    {
        if(!l1)
            return l2;
        if(!l2)
            return l1;
        ListNode *head = l1->val <= l2->val ? l1 : l2;
        head->next = l1->val <= l2->val ? merge2Lists(l1->next, l2) : merge2Lists(l1, l2->next);
        return head;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        if(lists.size() == 0)
            return NULL;
        ListNode *head = lists[0];
        for (int i = 1; i < lists.size();i++)
        {
            head = merge2Lists(head, lists[i]);
        }
        return head;
    }
};


class Solution {
public:
    ListNode* merge2Lists(ListNode* list1, ListNode* list2)
    {
        if(!list1)
            return list2;
        if(!list2)
            return list1;
        if(list1->val <= list2->val)
        {
            list1->next = merge2Lists(list1->next, list2);
            return list1;
        }
        else
        {
            list2->next = merge2Lists(list1, list2->next);
            return list2;
        }
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        int n = lists.size();
        if(n == 0)
            return NULL;
        while(n > 1)
        {
            for (int i = 0; i < n / 2;i++)
            {
                lists[i] = merge2Lists(lists[i], lists[n - 1 - i]);
            }
            n = (n + 1) / 2;
        }
        return lists[0];
    }
};