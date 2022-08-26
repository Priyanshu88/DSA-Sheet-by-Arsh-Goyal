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



void rearrange(Node* head)
{

    // finding the middle point using tortoise and hare

    Node *slow = head;
    Node *fast = slow->next;
    while(fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    // split 

}