// Rearrange a given linked list in-place.

// Difficulty Level : Medium
// Given a singly linked list L0 -> L1 -> … -> Ln-1 -> Ln. Rearrange the nodes in the list so that the new formed list is : L0 -> Ln -> L1 -> Ln-1 -> L2 -> Ln-2 … You are required to do this in place without altering the nodes’ values. 

// Examples: 

// Input:  1 -> 2 -> 3 -> 4
// Output: 1 -> 4 -> 2 -> 3

// Input:  1 -> 2 -> 3 -> 4 -> 5
// Output: 1 -> 5 -> 2 -> 4 -> 3

// Simple Solution

// 1) Initialize current node as head.
// 2) While next of current node is not null, do following
//     a) Find the last node, remove it from the end and insert it as next
//        of the current node.
//     b) Move current to next to next of current


// Better Solution: 

// Copy contents of the given linked list to a vector. 
// Rearrange the given vector by swapping nodes from both ends. 
// Copy the modified vector back to the linked list. 

#include<bits/stdc++.h>
using namespace std;

void Rearrange(Node* head)
{
    Node *p = head;
    vector<Node *> v;
    int l, i;
    while(p!=NULL)
    {
        v.push_back(p);
        p = p->next;

    }
    l = v.size();
    p = head;
    for (i = 0; i < l / 2; i++)
    {
        if(i!=0)
        {
            p->next = v[i];
            p = p->next;
        }
        p->next = v[l - i - 1];
        p = p->next;
    }
    if (l%2==1)
    {
        p->next = v[i];
        p = p->next;

    }
    p->next = NULL;
}


// Efficient Solution:

// 1) Find the middle point using tortoise and hare method.
// 2) Split the linked list into two halves using found middle point in step 1.
// 3) Reverse the second half.
// 4) Do alternate merge of first and second halves



Node* reverseList(Node* head)
{
    Node *prev = NULL;
    Node *curr = head;
    Node *next = NULL;

    while(curr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}


void rearrange(Node* head)
{

    // 1) finding the middle point using tortoise and hare
    // 

    Node *slow = head;
    Node *fast = slow->next;
    while(fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    // 2) Split the linked list in two halves
    // head1, head of first half    1 -> 2
    // head2, head of second half   3 -> 4

    Node *head1 = head;
    Node *head2 = slow->next;
    slow->next = NULL;

    // 3) Reverse the second half, i.e.,  4 -> 3
    
    head2 = reverseList(head2);
    
    // 4) Merge alternate nodes
    // assigning the dummy nodes

    Node* newH = new Node(0);


    while(head1 || head2)
    {

        // first add the element from list

        if(head1)
        {
            newH->next = head1;
            head1 = head1->next;
            newH = newH->next;

        }

        // then add the element from the second list

        if(head2)
        {
            newH->next = head2;
            head2 = head2->next;
            newH = newH->next;
        }
    }

    // assign the head od the new list to head pointer

    head = newH->next;
}


// 1. Take two pointers prev and curr, which hold the addresses of head and head-> next. 
// 2. Compare their data and swap. 

// After that, a new linked list is formed. 

void Rearrange_(Node* head)
{
    if( head == NULL)
    {
        return;
    }

    Node *prev = head;
    Node *curr = head->next;

    while(curr)
    {

        // swap function for swapping data

        if(prev->data > curr->data)
        {
            swap(prev->data, curr->data);
        }

        if(curr->next && curr->next->data > curr->data)
        {
            swap(curr->next->data, curr->data);

        }

        prev = curr->next;
        if(!curr->next)
            break;
        curr = curr->next->next;
    }
}


// Reorder List
// HardAccuracy: 49.92%Submissions: 37229Points: 8
// Given a singly linked list: A0→A1→…→An-1→An, reorder it to: A0→An→A1→An-1→A2→An-2→…
// For example: Given 1->2->3->4->5 its reorder is 1->5->2->4->3.

// Note: It is recommended do this in-place without altering the nodes' values.

// Example 1:

// Input:
// LinkedList: 1->2->3
// Output: 1 3 2
// Example 2:

// Input:
// LinkedList: 1->7->3->4
// Output: 1 4 7 3.
// Your Task:
// The task is to complete the function reorderList() which should reorder the list as required. The reorder list is automatically printed by the driver's code.

// Note: Try to solve without using any auxilliary space.

// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(1)

// Constraints:
// 1 <= N <= 104


void reorderList(Node* head)
{
    int r = 0,c;
    Node *temp,*temp1,*temp2, *p;
    temp = head;

     // if list contains 2 or lesser nodes, no change needed

    if(head == NULL || head->next == NULL || head->next->next == NULL)
        return;
    while(temp != NULL)
    {

        // finding number of nodes in list

        r++;
        temp = temp->next;

    }

    // c represents mid point

    c = (r + 1) / 2;

    temp = head;
    while(c--)
    {
        p = temp;
        temp = temp->next;
    }

    // dividing the list into 2
    // temp holds the address to head of second half

    p->next = NULL;

    temp1 = NULL;
    temp2 = temp;

    // reversing the second half of the list
    while(temp2!=NULL)
    {
        p = temp2->next;
        temp2->next = temp1;
        temp1 = temp2;
        temp2 = p;
    }

    // second half is now reversed

    p = temp1;

    // merging the 2 halves by selecting nodes
    // alternatively

    while(r--)
    {
        temp = p;
        p = head->next;
        head->next = temp;
        head = head->next;
    }
}