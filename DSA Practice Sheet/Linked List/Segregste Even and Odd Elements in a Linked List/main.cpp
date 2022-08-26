// Segregate even and odd nodes in a Linked List

// Difficulty Level : Medium
// Last Updated : 26 Jul, 2022
// Given a Linked List of integers, write a function to modify the linked list such that all even numbers appear before all the odd numbers in the modified linked list. Also, keep the order of even and odd numbers same.
// Examples:

// Input: 17->15->8->12->10->5->4->1->7->6->NULL
// Output: 8->12->10->4->6->17->15->5->1->7->NULL

// Input: 8->12->10->5->4->1->6->NULL
// Output: 8->12->10->4->6->5->1->NULL

// // If all numbers are even then do not change the list
// Input: 8->12->10->NULL
// Output: 8->12->10->NULL

// // If all numbers are odd then do not change the list
// Input: 1->3->5->7->NULL
// Output: 1->3->5->7->NULL

#include <bits/stdc++.h>
using namespace std;


//The idea is to split the linked list into two:  one containing all even nodes and other containing all odd nodes. And finally, attach the odd node linked list after the even node linked list. 
// To split the Linked List, traverse the original Linked List and move all odd nodes to a separate Linked List of all odd nodes. At the end of loop, the original list will have all the even 
// nodes and the odd node list will have all the odd nodes. To keep the ordering of all nodes same, we must insert all the odd nodes at the end of the even node list. And to do that in constant time,
// we must keep track of last pointer in the even node list.


class Solution
{
public:
    Node *divide(int N, Node *head)
    {

        // creating four dummy nodes for start and end node of even and start and end node of odd

        Node *even_Strt = NULL;
        Node *even_End = NULL;
        Node *odd_Strt = NULL;
        Node *odd_End = NULL;

        // traversing the list with curr pointer

        for (Node *curr = head; curr != NULL; curr = curr->next)
        {

            // storing the curr data in x

            int x = curr->data;

            // if x value is even

            if (x % 2 == 0)
            {

                // and start of even node is null

                if (even_Strt == NULL)
                {

                    //  then assign the curr to start of even node

                    even_Strt = curr;

                    // and point end of even on start of even

                    even_End = even_Strt;
                }

                // otherwise

                else
                {

                    // if start of even is not null
                    // that means there are already some even data nodes
                    // then assign curr to next of the end of even
                    // and move even_End to the even_End next

                    even_End->next = curr;
                    even_End = even_End->next;
                }
            }

            // if the node data is odd

            else
            {

                // and if start of odd is null that means there is no any element of odd data

                if (odd_Strt == NULL)
                {

                    // then assign curr to odd_Strt
                    // and end of odd will point on odd_Strt

                    odd_Strt = curr;
                    odd_End = odd_Strt;
                }

                // otherwise of there are already some odd elements then

                else
                {

                    // the curr will be the next of odd_End
                    // and odd_End will point to the next of odd_End

                    odd_End->next = curr;
                    odd_End = odd_End->next;
                }
            }
        }

        // if even and odd start nodes are found null

        if (odd_Strt == NULL || even_Strt == NULL)

            // then return head of the list

            return head;

        // otherwise connect the next of even_End with odd_Strt
        // and next of odd_End will be null
        // lastly return even_Strt i.e. head of the list

        even_End->next = odd_Strt;
        odd_End->next = NULL;
        return even_Strt;
    }
};


// The idea is to get pointer to the last node of list. And then traverse the list starting from the head node and move the odd valued nodes from their current position to end of the list.
// Algorithm: 
// …1) Get pointer to the last node. 
// …2) Move all the odd nodes to the end. 
//  ……a) Consider all odd nodes before the first even node and move them to end. 
//  ……b) Change the head pointer to point to the first even node. 
// ……b) Consider all odd nodes after the first even node and move them to the end. 


Node* segregateEvenOdd(Node * head)
{
    Node *end = head;
    Node *prev = NULL;
    Node *curr = head;

    while(end->next != NULL)
    {
        end = end->next;
    }

    Node *New_end = end;

    while((curr->data % 2) != 0 && curr != end)
    {
        New_end->next = curr;
        curr = curr->next;
        New_end->next->next = NULL;
        New_end = New_end->next;
    }

    if(curr->data%2==0)
    {
        *head = curr;
        while(curr != end)
        {
            if((curr->data)%2 == 0)
            {
                prev = curr;
                curr = curr->next;
            }
            else
            {
                prev->next = curr->next;
                curr->next = NULL;
                new_end->next = curr;
                new_end = curr;
                curr = prev->next;
            }
        }
    }
    else
        prev = curr;
    
    if(New_end != end && (end->data)%2 != 0)
    {
        prev->next = end->next;
        end->next = NULL;
        New_end->next = end;
    }

    return;

}   