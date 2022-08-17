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
    ListNode* sortList(ListNode* head) {

        //If List Contain a Single or 0 Node

        if(head == NULL || head->next == NULL)
            return head;
        ListNode* temp = NULL;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != NULL && fast->next != NULL)
        {
            temp = slow;
            slow = slow->next; //slow increment by 1
            fast = fast->next->next; //fast incremented by 2
        }
        temp->next = NULL; //end of first left half
        ListNode* l1 = sortList(head);  //left half recursive call
        ListNode* l2 = sortList(slow);  //right half recursive call
        return MergeList(l1,l2);  //mergelist Function call
    }
    
    ListNode* MergeList(ListNode* l1, ListNode* l2)
    {
        ListNode* ptr = new ListNode(0);
        ListNode* curr = ptr;
        while(l1 != NULL && l2 != NULL)
        {
            if(l1->val <= l2->val)
            {
                curr->next = l1;
                l1 = l1->next;
            }
            else
            {
                curr->next = l2;
                l2 = l2->next;
            }
            curr = curr->next;
        }

        //for unqual length linked list
        

        if(l1 != NULL)
        {
            curr->next = l1;
            l1 = l1->next;
        }
        if(l2 != NULL)
        {
            curr->next = l2;
            l2 = l2->next;
        }
        return ptr->next;
    }
};



class Solution {
public:
    
    ListNode* getMid(ListNode* head)
    {
        ListNode* midPrev = nullptr;
        while(head && head->next)
        {
            midPrev = (midPrev == nullptr) ? head : midPrev->next;
            head = head->next->next;
        }
        ListNode* mid = midPrev->next;
        midPrev->next = nullptr;
        return mid;
    }
    
    ListNode* merge(ListNode* list1, ListNode* list2)
    {
        ListNode dummyHead(0);
        ListNode* ptr = &dummyHead;
        while(list1 && list2)
        {
            if(list1->val < list2->val)
            {
                ptr->next = list1;
                list1 = list1->next;
            }
            else
            {
                ptr->next = list2;
                list2 = list2->next;
            }
            ptr = ptr->next;
        }
        if(list1) ptr->next = list1;
        else ptr->next = list2;
        return dummyHead.next;
    }
    
    
    ListNode* sortList(ListNode* head) 
    {
        if(!head || !head->next)
            return head;
        ListNode* mid = getMid(head);
        ListNode* left = sortList(head);
        ListNode* right = sortList(mid);
        return merge(left,right);
    }
};