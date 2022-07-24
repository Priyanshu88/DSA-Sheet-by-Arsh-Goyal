    /*
    struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
    }*head;
    */


class Solution
{
    public:
    //Function to delete a node without any reference to head pointer.
    
    // copying the data of next node and deleting the next node and deleting the memory but this trick would not work if node to be deleted is last node if we try to access next arrow data then we get segmentation fault
    
    void deleteNode(Node *del)
    {
        Node* temp = del->next;
        del->data = temp->data;
        del->next = temp->next;
        delete (temp);
    }

};