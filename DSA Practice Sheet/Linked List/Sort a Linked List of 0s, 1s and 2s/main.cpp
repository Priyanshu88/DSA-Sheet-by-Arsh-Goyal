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

    void insertAtTail (Node* &tail, Node* curr)
    {
        tail->next = curr;
        tail = curr;
    }


    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) 
    {


    // Creating three dummy nodes to point to beginning of
    // three linked lists for 0s, 1s and 2s. these dummy nodes are created to
    // avoid many null checks. initializing tail pointers for three
    // lists to merge the list and whole list. 

        Node* zeroHead = new Node(-1);
        Node* zeroTail = zeroHead;
        Node* oneHead = new Node(-1);
        Node* oneTail = oneHead;
        Node* twoHead = new Node(-1);
        Node* twoTail = twoHead;


        // initializing curr pointer for head

        Node* curr = head;

        // traversing the list until curr becomes null

        while(curr != NULL)
        {

            // storing cur data in value for comparision

            int value = curr->data;

            // if  value is equal to 0

            if(value == 0)
            {

                // inserting curr to the tail of zero

                insertAtTail(zeroTail, curr);
            }
            
            // if  value is equal to 1

            else if(value == 1)
            {

                // inserting curr to the tail of one

                insertAtTail(oneTail, curr);
            }

            // if  value is equal to 2

            else if(value == 2) 
            {

                // inserting curr to the tail of two

                insertAtTail(twoTail, curr);
            }

            // moving curr to curr next

            curr = curr->next;
        }

        // if oneHead next is not null
        // then only linking the zeroTail next to oneHead next

        if(oneHead->next != NULL)
        {
            zeroTail->next = oneHead->next;

        }

        // if oneHead next is null
        // then linking zeroTail next with twoHead next

        else
        {
            zeroTail->next = twoHead->next;
        }

        // and linking the oneTail next with twoHead next
        // also assigning null to twoTail next

        oneTail->next = twoHead->next;
        twoTail->next = NULL;

        // making head point on zeroHead next

        head = zeroHead->next;

        // deleting the the all three dummy nodes 

        delete zeroHead;
        delete oneHead;
        delete twoHead;

        // and returning the head

        return head;
    }    
};



// T.C.:O(n)
// S.C.O(1)
