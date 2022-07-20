/*

    Node is defined as
    struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

// count the occurrences and replace in order

class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) 
    {
        
        // taking count of 0s, 1s and 2s

        int zeroCount = 0;
        int oneCount = 1;
        int twoCount = 2;

        // temp node assigned by head

        Node* temp = head;

        // traversing until temp becomes null 

        while(temp != NULL)
        {
            
            // if temp data is 0
            // increase the count of 0

            if(temp->data == 0)
                zeroCount++;

            // if temp data is 1
            // increase the count of 1

            else if(temp->data ==  1)
                oneCount++;

            // if temp data is 2
            // increase the count of 2

            else if(temp->data == 2)
                twoCount++;

            // move forward with temp next

            temp = temp->next;
        }

        // assign head to temp again

        temp = head;

        // traversing until temp becomes null

        while(temp != NULL)
        {
            
            // store 0 in temp data until count of 0 i.e. zeroCount becomes 0
            // by decrementing the zeroCount

            if(zeroCount != 0)
            {
                temp->data = 0;
                zeroCount--;

            }

            // store 1 in temp data until count of 1 i.e. oneCount becomes 0
            // by decrementing the zeroCount

            else if(oneCount != 0)
            {
                temp->data = 1;
                oneCount--;

            }

            // store 2 in temp data until count of 2 i.e. twoCount becomes 0
            // by decrementing the zeroCount

            else if(twoCount != 0)
            {
                temp->data = 2;
                twoCount--;
            }

            // moving forward with temp next

            temp = temp->next;
        }

        // returning head
        
        return head;
    }
};
    
// T.C.:O(n)
// S.C.O(1)



// if data replacement is not allowed

class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) 
    {

    }    
};



// T.C.:O(n)
// S.C.O(1)
