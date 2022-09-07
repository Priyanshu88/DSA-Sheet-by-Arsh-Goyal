// Subtract Two Numbers represented as Linked Lists

// Difficulty Level : Hard
// Last Updated : 26 Jul, 2022
// Given two linked lists that represent two large positive numbers. Subtract the smaller number from the larger one and return the difference as a linked list. Note that the input lists may be in any order, but we always need to subtract smaller from the larger ones.
// It may be assumed that there are no extra leading zeros in input lists.
// Examples: 
// Input: l1 = 1 -> 0 -> 0 -> NULL,  l2 = 1 -> NULL
// Output: 0->9->9->NULL
// Explanation: Number represented as 
// lists are 100 and 1, so 100 - 1 is 099

// Input: l1 = 7-> 8 -> 6 -> NULL,  l2 = 7 -> 8 -> 9 NULL
// Output: 3->NULL
// Explanation: Number represented as 
// lists are 786 and  789, so 789 - 786 is 3, 
// as the smaller value is subtracted from 
// the larger one.


// Approach: Following are the steps. 
// Calculate sizes of given two linked lists.
// If sizes are not the same, then append zeros in the smaller linked list.
// If the size is the same, then follow the below steps:
// Find the smaller valued linked list.
// One by one subtract nodes of the smaller-sized linked list from the larger size. Keep track of borrow while subtracting.


// /* A utility function to get length of linked list 

int getLength(Node* Node)
{
    int size = 0;
    while(Node!=NULL)
    {
        Node = Node->next;
        size++;
    }
    return size;
}

// A Utility that padds zeros in front of the Node, with the given diff

Node* paddZeros(Node* sNode, int diff)
{
    if(sNode == NULL)
        return NULL;
    Node *zHead = newNode(0);
    diff--;
    Node *temp = zHead;
    while(diff--)
    {
        temp->next = newNode(0);
        temp = temp->next;
    }

    temp->next = sNode;
    return zHead;
}

// Subtract LinkedList Helper is a recursive function,move till the last Node, and subtract the digits and create the Node and return the Node. If d1 < d2, we borrow the number from previous digit.

Node* subtractLinkedListHelper(Node* l1, Node* l2, bool& borrow)
{

    if (l1 == NULL && l2 == NULL && borrow == 0)
        return NULL;

    Node *previous = subtractLinkedListHelper(l1 ? l1->next : NULL, l2 ? l2->next : NULL, borrow);

    int d1 = l1->data;
    int d2 = l2->data;
    int sub = 0;

    // if you have given the value to next digit then reduce the d1 by 1

    if(borrow)
    {
        d1--;
        borrow = false;
    }

    // If d1 < d2, then borrow the number from previous digit. Add 10 to d1 and set borrow = true;

    if(d1<d2)
    {
        borrow = true;
        d1 = d1 + 10;
    }

    // subtract the digits

    sub = d1 - d2;

    // Create a Node with sub value

    Node *current = newNode(sub);

    // Set the Next pointer as Previous

    return current;
}


// This API subtracts two linked lists and returns the linked list which shall  have the subtracted result.

Node* subtractLinkedList(Node *l1,Node *l2)
{

    // base case

    if(l1==NULL && l2==NULL)
        return NULL;
    
    // In either of the case, get the lengths of both Linked list.

    int len1 = getLength(l1);
    int len2 = getLength(l2);
    Node *largeNode = NULL, *smallNode = NULL;
    Node *temp = l1;
    Node *temp2 = l2;

    // If lengths differ, calculate the smaller Node
    // and add zeros for smaller Node and ensure both
    // larger Node and smaller Node has equal length.

    if(len1!=len2)
    {
        largeNode = len1 > len2 ? l1 : l2;
        smallNode = len1 > len2 ? l2 : l1;

        smallNode = paddZeros(smallNode, abs(len1 - len2));
    }

    else
    {

        // If both list lengths are equal, then calculate
        // the larger and smaller list. If 5-6-7 & 5-6-8
        // are linked list, then walk through linked list
        // at last Node as 7 < 8, larger Node is 5-6-8
        // and smaller Node is 5-6-7.

        while(l1&&l2)
        {
            if(l1->data != l2->data)
            {
                largeNode = l1->data > l2->data ? temp1 : temp2;
                smallNode = l1->data > l2->data ? temp2 : temp1;
                break;
            }
            l1 = l1->next;
            l2 = l2->next;
        }
    }

    // If both lNode and sNode still have NULL value,
    // then this means that the  value of both of the given
    // linked lists is the same and hence we can directly
    // return a node with value 0.

    if(largeNode == NULL && smallNode == NULL)
    {
        return newNode(0);
    }

    // After calculating larger and smaller Node, call
    // subtractLinkedListHelper which returns the subtracted linked list.

    bool borrow = false;
    return subtractLinkedListHelper(largeNode, smallNode, borrow);
}


// T.C.:O(n)
// S.C.:O(n)

