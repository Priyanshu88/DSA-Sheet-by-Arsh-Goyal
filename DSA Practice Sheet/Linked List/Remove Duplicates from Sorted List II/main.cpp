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

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {

        // if head is null or there is just one node return head

        if (head == NULL || head->next == NULL)
            return head;

        // if we have more than one nodes
        // keeping next pointer on head next

        ListNode *next = head->next;

        // if next val is equal to head val
        // then exclude head and all the nodes which are same as head

        if (next->val == head->val)
        {

            // so while next does not become null and head val is equal to next val

            while (next != NULL && head->val == next->val)

                // keep incrementing next

                next = next->next;

            // now this head val is different from next we stop
            // and we forget about all the nodes from head till previous next so next will be new head as all of those nodes
            // are duplicates so those will not be in the result
            // so return the recursively next

            return deleteDuplicates(next);
        }

        // when next is different from head as it will be the part of solution

        else
        {

            // so it's next will be whatever is returned by duplicate on next
            // finally return new head

            head->next = deleteDuplicates(next);
            return head;
        }
    }
};

// T.C.:O(n)
// S.C.:O(1)

class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {

        // sentinel

        ListNode *sentinel = new ListNode(0, head);

        // predecessor = the last node
        // before the sublist of duplicates

        ListNode *pred = sentinel;

        while (head != NULL)
        {

            // if it is a beginning of duplicates sublist
            // skipping all duplicates

            if (head->next != NULL && head->val == head->next->val)
            {

                // moving till the end of duplicates sublist

                while (head->next != NULL && head->val == head->next->val)
                {
                    head = head->next;
                }

                // skipping all duplicates

                pred->next = head->next;

                // otherwise moving predecessor
            }
            else
            {
                pred = pred->next;
            }

            // moving forward in the list

            head = head->next;
        }

        return sentinel->next;
    }
};

// T.C.:O(n)
// S.C.:O(1)