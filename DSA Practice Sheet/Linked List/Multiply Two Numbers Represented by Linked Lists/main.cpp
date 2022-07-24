
/* Linked list node structure
struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};*/

/*The method multiplies 
two  linked lists l1 and l2
and returns their product*/

/*You are required to complete this method*/

// Traversing both lists and generating the required numbers to be multiplied and then return the multiplied values of the two numbers. 

long long  multiplyTwoLists (Node* l1, Node* l2)
{   

    // initializing the n for large values
    
    long long n = 1000000007;
    
    // initializing variables to zero and traversing the linked list
    // if the list is l1 then add the value of first node to this variable num1
    // if the list is l2 then add the value of first node to this variable num2
    // from the second node of both the lists, multiply by 10 and take modulo with n then add the value of node to this variable
    // repeat this step till last node and move l1 to l1 next in each step


    long long num1 = 0, num2 = 0;
    while (l1 ||  l2)
    {
        if(l1) 
        {
            num1 = ((num1)*10)%n + l1->data;
            l1 = l1->next;
        }
        if(l2)
        {
            num2 = ((num2)*10)%n + l2->data;
            l2 = l2->next
        }
    }

    // returning the multiplied value

    return ((num1%n)*(num2%n))%n;
    
}


// T.C. : O(n)
// S.C. :O(1)