/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */



// 92. Reverse Linked List II
// Medium
// 8K
// 352
// Companies
// Given the head of a singly linked list and two integers left and right where left <= right, reverse the nodes of the list from position left to position right, and return the reversed list.

// Example 1:

// Input: head = [1,2,3,4,5], left = 2, right = 4
// Output: [1,4,3,2,5]
// Example 2:

// Input: head = [5], left = 1, right = 1
// Output: [5]

// Constraints:

// The number of nodes in the list is n.
// 1 <= n <= 500
// -500 <= Node.val <= 500
// 1 <= left <= right <= n

// Follow up: Could you do it in one pass?



// https://leetcode.com/problems/reverse-linked-list-ii/solutions/215957/reverse-linked-list-ii/

// We define a recursion function that will do the job of reversing a portion of the linked list.
// Let's call this function recurse. The function takes in 3 parameters: m being the starting point of the reversal, n being the ending point for the reversal, and a pointer right which will start at the nthn^{th}n 
// th
//   node in the linked list and move backwards with the backtracking of the recursion. If this is not clear at the moment, the diagrams that follow will help.
// Additionally, we have a pointer called left which starts from the mthm^{th}m 
// th
//   node in the linked list and moves forward. In Python, we have to take a global variable for this which get's changed with recursion. In other languages, where changes made in function calls persist, we can consider this pointer as an additional variable for the function recurse.
// In a recursion call, given m, n, and right, we check if n == 1. If this is the case, we don't need to go any further.
// Until we reach n = 1, we keep moving the right pointer one step forward and after doing that, we make a recursive call with the value of n decreased by 1. At the same time, we keep on moving the left pointer forward until m == 1. When we refer to a pointer being moved forward, it essentially means pointer.next.
// So we backtrack as soon as n reaches 1. At that point of time, the right pointer is at the last node of the sublist we want to reverse and the left has already reached the first node of this sublist. So, we swap out the data and move the left pointer one step forward using left = left.next. We need this change to persist across the backtracking process.
// From there on, every time we backtrack, the right pointer moves one step backwards. This is the simulation we've been mentioning all along. The backward movement is simulated by backtracking.
// We stop the swaps when either right == left, which happens if the sublist size is odd, or, right.next == left which happens when during the backtracking process for an even sized sublist, the right pointer crosses left. We use a global boolean flag for stopping the swaps once these conditions are met.

class Solution {
public:
    
    ListNode *l;
    bool stop;

    void recurseAndReverse(ListNode* right, int m, int n)
    {
        if(n==1)
        {
            return;
        }

        right = right->next;

        if(m > 1)
        {
            l = l->next;
        }

        recurseAndReverse(right, m-1, n-1);

        if(l == right || right->next == l)
        {
            stop = true;
        }

        if(!stop)
        {
            int t = l->val;
            l->val = right->val;
            right->val = t;

            l = l->next;
        }
    }

    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        l = head;
        stop = false;
        recurseAndReverse(head, left, right);
        return head;
    }
};




// We need two pointers, prev and cur as explained above.

// The prev pointer should be initialized to None initially while cur is initialized to the head of the linked list.

// We progress the cur pointer one step at a time and the prev pointer follows it.

// We keep progressing the two pointers in this way until the cur pointer reaches the mthm^{th}m 
// th
//   node from the beginning of the list. This is the point from where we start reversing our linked list.

// An important thing to note here is the usage of two additional pointers which we will call as tail and con. The tail pointer points to the mthm^{th}m 
// th
//   node from the beginning of the linked list and we call it a tail pointer since this node becomes the tail of the reverse sublist. The con points to the node one before mthm^{th}m 
// th
//   node and this connects to the new head of the reversed sublist. Let's take a look at a figure to understand these two pointers better.


// The tail and the con pointers are set once initially and then used in the end to finish the linked list reversal.

// Once we reach the mthm^{th}m 
// th
//   node, we iteratively reverse the links as explained before using the two pointers. We keep on doing this until we are done reversing the link (next pointer) for the nthn^{th}n 
// th
//   node. At that point, the prev pointer would point to the nthn^{th}n 
// th
//   node.

// We use the con pointer to attach to the prev pointer since the node now pointed to by the prev pointer (the nthn^{th}n 
// th
//   node from the beginning) will come in place of the mthm^{th}m 
// th
//   node due after the reversal. Similarly, we will make use of the tail pointer to connect to the node next to the prev node i.e. (n+1)th(n+1)^{th}(n+1) 
// th
//   node from the beginning.


    class Solution
    {
    public:
        ListNode *reverseBetween(ListNode *head, int left, int right)
        {

            // Empty list

            if (head == NULL)
                return NULL;

            // Move the two pointers until they reach the proper starting point in the list.

            ListNode *curr = head, *prev = NULL;
            while (left > 1)
            {
                prev = curr;
                curr = curr->next;
                left--;
                right--;
            }

            // The two pointers that will fix the final connections.

            ListNode *con = prev, *tail = curr;

            // Iteratively reverse the nodes until n becomes 0.

            ListNode *third = NULL;
            while (right > 0)
            {
                third = curr->next;
                curr->next = prev;
                prev = curr;
                curr = third;
                right--;
            }

            // Adjust the final connections as explained in the algorithm

            if (con != NULL)
            {
                con->next = prev;
            }
            else
            {
                head = prev;
            }

            tail->next = curr;
            return head;
        }
};