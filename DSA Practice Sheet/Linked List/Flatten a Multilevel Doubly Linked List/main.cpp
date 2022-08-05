/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

// start from head node move one step each time to the next node
// when meet with a node with child as p follow its child chain to the end and connect the tail node with p->next,
// by doing this we merged the child chain back to the main thread
// return to p and proceed until find next node with child
// repeat until reach null

class Solution
{
public:
    Node *flatten(Node *head)
    {

        // base case

        if (head == NULL)
            return head;

        // p pointer pointing on head

        Node *p = head;

        // traversing p until it does not become null

        while (p != NULL)
        {

            // if there is no child proceed

            if (p->child == NULL)
            {
                p = p->next;
                continue;
            }

            
            // if child found finding the tail of child and linking to the p->next
            
            Node *temp = p->child;

            // finding tail of the child

            while (temp->next != NULL)
            {

                // connecting tail with p next, if it is not null

                temp = temp->next;
            }
            temp->next = p->next;
            if (p->next != NULL)
                p->next->prev = temp;

            // connecting p with p child and removing p child
            
            p->next = p->child;
            p->child->prev = p;
            p->child = NULL;
        }
        return head;
    }
};

// T.C.:O(n)
// S.C.:O(1)


// 

class Solution
{
public:
    Node *flatten(Node *head)
    {
        for (Node *h = head; h; h = h->next)
        {
            if(h->child)
            {
                Node *next = h->next;
                h->next = h->child;
                h->next->prev = h;
                h->child = NULL;
                Node *p = h->next;
                while(p->next)
                    p = p->next;
                p->next = next;
                if(next)
                    next->prev = p;
            }
        }
        return head;
    }
};

