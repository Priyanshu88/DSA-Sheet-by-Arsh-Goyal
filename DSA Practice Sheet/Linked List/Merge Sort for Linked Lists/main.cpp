#include<bits/stdc++.h>
using namespace std;
// Let the head be the first node of the linked list to be sorted and headRef be the pointer to head. Note that we need a reference to head in MergeSort() as the below implementation changes next links to sort the linked lists (not data at the nodes), so the head node has to be changed if the data at the original head is not the smallest value in the linked list. 

// MergeSort(headRef)
// 1) If the head is NULL or there is only one element in the Linked List 
//     then return.
// 2) Else divide the linked list into two halves.  
//       FrontBackSplit(head, &a, &b); /* a and b are two halves */
// 3) Sort the two halves a and b.
//       MergeSort(a);
//       MergeSort(b);
// 4) Merge the sorted a and b (using SortedMerge() discussed here) 
//    and update the head pointer using headRef.
//      *headRef = SortedMerge(a, b);

// mergeSort():

// If the size of the linked list is 1 then return the head
// Find mid using The Tortoise and The Hare Approach
// Store the next of mid in head2 i.e. the right sub-linked list.
// Now Make the next midpoint null.
// Recursively call mergeSort() on both left and right sub-linked list and store the new head of the left and right linked list.
// Call merge() given the arguments new heads of left and right sub-linked lists and store the final head returned after merging.
// Return the final head of the merged linkedlist.
// merge(head1, head2):

// Take a pointer say merged to store the merged list in it and store a dummy node in it.
// Take a pointer temp and assign merge to it.
// If the data of head1 is less than the data of head2, then, store head1 in next of temp & move head1 to the next of head1.
// Else store head2 in next of temp & move head2 to the next of head2.
// Move temp to the next of temp.
// Repeat steps 3, 4 & 5 until head1 is not equal to null and head2 is not equal to null.
// Now add any remaining nodes of the first or the second linked list to the merged linked list.
// Return the next of merged(that will ignore the dummy and return the head of the final merged linked list)


Node* merge(Node* firstNode, Node* secondNode)
{
    Node *merged = new Node;
    Node *temp = new Node;

    // merged is equal to temp so in the end we have the top Node.
    
    merged = temp;

    // while either firstNode or secondNode becomes NULL


}


// Merge Sort for Linked List
// MediumAccuracy: 52.29%Submissions: 47074Points: 4
// Given Pointer/Reference to the head of the linked list, the task is to Sort the given linked list using Merge Sort.
// Note: If the length of linked list is odd, then the extra node should go in the first list while splitting.

// Example 1:

// Input:
// N = 5
// value[]  = {3,5,2,4,1}
// Output: 1 2 3 4 5
// Explanation: After sorting the given
// linked list, the resultant matrix
// will be 1->2->3->4->5.
// Example 2:

// Input:
// N = 3
// value[]  = {9,15,0}
// Output: 0 9 15
// Explanation: After sorting the given
// linked list , resultant will be
// 0->9->15.
// Your Task:
// For C++ and Python: The task is to complete the function mergeSort() which sort the linked list using merge sort function.
// For Java: The task is to complete the function mergeSort() and return the node which can be used to print the sorted linked list.

// Expected Time Complexity: O(N*Log(N))
// Expected Auxiliary Space: O(N)

// Constraints:
// 1 <= N <= 105

/* Structure of the linked list node is as
struct Node 
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};
*/


class Solution 
{
    public:

    Node* mid(Node* head)
    {
        Node *slow = head;
        Node *fast = head->next;
        while(fast!=NULL && fast->next!=NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }



    Node* merge(Node* left, Node*right)
    {
        if(left==NULL)
            return right;
        if(right==NULL)
            return left;
        Node *ans = new Node(-1);
        Node* temp = ans;
        while(left != NULL && right != NULL)
        {
            if(left->data < right->data)
            {
                temp->next = left;
                temp = left;
                left = left->next;
            }
            else
            {
                temp->next = right;
                temp = right;
                right = right->next;

            }
        }
        while(left != NULL)
        {
            temp->next = left;
            temp = left;
            left = left->next;

        }
        while(right != NULL)
        {
            temp->next = right;
            temp = right;
            right = right->next;
        }
        ans = ans->next;
        return ans;
    }



    Node* mergeSort(Node* head)
    {
        if(head == NULL || head->next == NULL)
        {
            return head;

        }
        Node *findMid = mid(head);
        Node *left = head;
        Node *right = mid->next;
        mid->next = NULL;
        left = mergeSort(left);
        right = mergeSort(right);

        Node *result = merge(left, right);
        return result;
    }

};



class Solution 
{
    public:
    Node* merge(Node *l1, Node *l2) {
        if(l1 == NULL)
            return l2;
        if(l2 == NULL)
            return l1;
        if(l1->data > l2->data)
        {
            l2->next = merge(l1, l2->next);
            return l2;
        }
        else
        {
            l1->next = merge(l1->next, l2);
            return l1;
        }
    }

    Node* mergeSort(Node* head)
    {
        if(head == NULL || head->next == NULL)
            return head;
        Node *temp = NULL;
        Node *slow = head;
        Node *fast = head;
        while(fast && fast->next)
        {
            temp = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        temp->next = NULL;
        Node *l1 = mergeSort(head);
        Node *l2 = mergeSort(slow);
        return merge(l1, l2);
    }
};

