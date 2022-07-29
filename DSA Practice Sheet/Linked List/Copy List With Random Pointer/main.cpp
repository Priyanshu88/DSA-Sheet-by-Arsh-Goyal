/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> mp;
        Node* temp = head;

        // making clone of linkedlist

        while(temp != NULL)
        {

            // assigning the original node value

            Node* copy = new Node(temp->val);

            // mapping temp with copy

            mp[temp] = copy;

            // moving forward in temp

            temp = temp->next;

        }

        // temp will be head now

        temp = head;

        // making connections

        while (temp != NULL)
        {

            // copy of temp  next will be temp next of the copy

            mp[temp]->next = mp[temp->next];

            // map of tamp random pointer will be copy of temp random 

            mp[temp]->random = mp[temp->random];

            // moving forward in list

            temp = temp->next;

        }

        // returning the head

        return mp[head];
        

    }
};

// O(n)
// (1)


class Solution {
public:
    Node* copyRandomList(Node* head) {

        // base case

        if(head == NULL)
        return head;

        // creating the copy of list in between with curr value and adding to the next of original 
        // and random as null

        Node* curr = head;
        while(curr != NULL)
        {
            Node* temp = curr->next;
            curr->next = new Node(curr->val, temp, NULL);
            curr = temp;
        }

        // curr point on head

        curr = head;

        // connecting the random pointer as per the original list

        while(curr != NULL)
        {
            if(curr->random != NULL)
            {
                curr->next->random = curr->random->next;
            }

            curr = curr->next->next;
        }

        curr = head;
        
        // linking the node by skipping one node
        // returning the copy head

        Node* copyHead = head->next;

        while(curr != NULL)
        {
            Node* temp = curr->next->next;
            Node* copy = curr->next;
            curr->next = temp;
            if(temp != NULL)
            {
                copy->next = temp->next;
            }

            curr = temp;

        }

    return copyHead;

    }
};

// T.C.: (n)
// S.C.: O(1)