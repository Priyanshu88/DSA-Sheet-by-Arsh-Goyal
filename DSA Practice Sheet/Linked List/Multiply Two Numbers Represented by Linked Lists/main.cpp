
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
long long  multiplyTwoLists (Node* l1, Node* l2)
{
    long long n = 1000000007;
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
    return ((num1%n)*(num2%n))%n;
    
}