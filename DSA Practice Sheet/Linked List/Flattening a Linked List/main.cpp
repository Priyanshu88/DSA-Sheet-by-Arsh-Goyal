// Flattening a Linked List

// Difficulty Level : Hard
// Last Updated : 08 Aug, 2022
// Given a linked list where every node represents a linked list and contains two pointers of its type: 

// Pointer to next node in the main list (we call it ‘right’ pointer in the code below) 
// Pointer to a linked list where this node is headed (we call it the ‘down’ pointer in the code below). 
// Note: All linked lists are sorted and the resultant linked list should also be sorted

// Examples: 

// Input:    5 -> 10 -> 19 -> 28
//                |        |         |        |
//               V       V       V       V
//               7      20      22     35
//                |                 |        |
//               V               V       V
//               8               50     40
//               |                          |
//              V                        V
//             30                       45

// Output: 5->7->8->10->19->20->22->28->30->35->40->45->50

// Input:    3 -> 10 -> 7 -> 14
//                |        |         |        |
//               V       V       V       V
//               9      47      15     22
//                |                 |        
//               V                V      
//               17              30

// Output: 3->9->7->10->14->15->17->22->30->47  


#include<bits/stdc++.h>
using namespace std;

// The idea is to use the Merge() process of merge sort for linked lists. Use merge() to merge lists one by one, recursively merge() the current list with the already flattened list. The down pointer is used to link nodes of the flattened list.

// Recursively call to merge the current linked list with the next linked list
// If the current linked list is empty or there is no next linked list then return the current linked list (Base Case)
// Start merging the linked lists, starting from the last linked list
// After merging the current linked list with the next linked list, return the head node of the current linked list

// struct Node{
// 	int data;
// 	struct Node * next;
// 	struct Node * bottom;
	
// 	Node(int x){
// 	    data = x;
// 	    next = NULL;
// 	    bottom = NULL;
// 	}
	
// };

Node*merge(Node*a, Node* b)
{

    // if the first linked list is empty then return second

    if(a == NULL)
        return b;

    // if the first linked list is empty then return second

    if(b==NULL)
        return a;

    // Compare the data members of the two linked
    // lists and put the larger one in the result

    Node *result;
    if(a->data < b->data)
    {
        result = a;
        result->bottom = merge(a->bottom, b);

    }
    else
    {
        result = b;
        result->bottom = merge(a, b->bottom);
    }
    result->next = NULL;
    return result;
}

Node* flatten(Node* root)
{

    // base case

    if(root == NULL || root->next == NULL)
        return root;

    // Recur for the list on right side

    root->next = flatten(root->next);

    // now merge

    root = merge(root, root->next);

    // return the root 
    // it will be in turned with its left

    return root;

}


// Time Complexity: O(N * N * M) – where N is the no of nodes in the main linked list and M is the no of nodes in a single sub-linked list 
// Explanation: As we are merging 2 lists at a time,

// After adding the first 2 lists, the time taken will be O(M+M) = O(2M).
// Then we will merge another list to above merged list -> time = O(2M + M) = O(3M).
// Then we will merge another list -> time = O(3M + M).
// We will keep merging lists to previously merged lists until all lists are merged.
// Total time taken will be O(2M + 3M + 4M + …. N*M) = (2 + 3 + 4 + … + N) * M
// Using arithmetic sum formula: time = O((N * N + N – 2) * M/2)
// The above expression is roughly equal to O(N * N * M) for a large value of N
// Auxiliary Space: O(N*M) – because of the recursion. The recursive functions will use a recursive stack of a size equivalent to a total number of elements in the lists, which is N*M.



// Flattening a Linked List using Priority Queues:
// The idea is, to build a Min-Heap and push head node of every linked list into it and then use Extract-min function to get minimum element from priority queue and then move forward in that linked list.

// Follow the given steps to solve the problem:

// Create a priority queue(Min-Heap) and push the head node of every linked list into it
// While the priority queue is not empty, extract the minimum value node from it and if there is a next node linked to the minimum value node then push it into the priority queue
// Also, print the value of the node every time after extracting the minimum value node

struct mycomp {
    bool operator() (Node*a, Node*b)
    {
        return a->data > b->data;
    }
}

void flatten(Node* root)
{
    priority_queue<Node *, vector<Node *>, mycomp> p;

    // priority_queue<Node *, vector<Node *>, greater<Node*>> p;

    // pushing main link nodes into priority_queue.

    while(root != NULL)
    {
        p.push(root);
        root = root->next;

    }

    // Extracting the minimum node
    // while priority queue is not empty

    while(!p.empty())
    {

        // extracting min

        auto k = p.top();
        p.pop();

        cout << k->data << " ";
        if(k->bottom)
            p.push(k->bottom);
    }

}

// Time Complexity: O(N * M * log(N)) – where N is the no of nodes in the main linked list (reachable using the next pointer) and M is the no of nodes in a single sub-linked list (reachable using a bottom pointer).
// Auxiliary Space: O(N) - where N is the no of nodes in the main linked list (reachable using the next pointer).

Node* flatten(Node* root)
{
    Node *ptr = root;
    Node*head = NULL;
    priority_queueNode *, vector<Node *>, greater < Node * >> pq;

    while(ptr!=NULL)
    {
        pq.push(ptr);
        ptr = ptr->next;
    }
    while(!pq.empty())
    {
        Node *temp = pq.top();
        pq.pop();
        if(temp->down != NULL)
            pq.push(temp->down);
        if(head == NULL)
        {
            head = temp;
            ptr = temp;
            ptr->next = NULL;

        }
        else
        {
            ptr->bottom = temp;
            ptr = temp;
            ptr-> right = NULL;
        }

    }
    return head;
}
