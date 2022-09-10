// Stack | Set 4 (Evaluation of Postfix Expression)

// Difficulty Level : Easy
// Last Updated : 22 Aug, 2022
 
// The Postfix notation is used to represent algebraic expressions. The expressions written in postfix form are evaluated faster compared to infix notation as parenthesis is not required in postfix. We have discussed infix to postfix conversion. In this post, the evaluation of postfix expressions is discussed.

 
// Example: 

// Input: str = “2 3 1 * + 9 -“
// Output: -4
// Explanation: 

// Scan 2, it’s a number, so push it to stack. Stack contains ‘2’ 
// Scan 3, again a number, push it to stack, stack now contains ‘2 3’ (from bottom to top) 
// Scan 1, again a number, push it to stack, stack now contains ‘2 3 1’ 
// Scan *, it’s an operator, pop two operands from stack, apply the * operator on operands, we get 3*1 which results in 3. We push the result 3 to stack. The stack now becomes ‘2 3’. 
// Scan +, it’s an operator, pop two operands from stack, apply the + operator on operands, we get 3 + 2 which results in 5. We push the result 5 to stack. The stack now becomes ‘5’. 
// Scan 9, it’s a number, so we push it to the stack. The stack now becomes ‘5 9’. 
// Scan -, it’s an operator, pop two operands from stack, apply the – operator on operands, we get 5 – 9 which results in -4. We push the result -4 to the stack. The stack now becomes ‘-4’. 
// There are no more elements to scan, we return the top element from the stack (which is the only element left in a stack).
// Input: str = “100 200 + 2 / 5 * 7 +”
// Output: 757

// Evaluation of Postfix Expression Using Stack:
// Follow the steps mentioned below to evaluate postfix expression using stack:

// Create a stack to store operands (or values). 
// Scan the given expression from left to right and do the following for every scanned element. 
// If the element is a number, push it into the stack 
// If the element is an operator, pop operands for the operator from the stack. Evaluate the operator and push the result back to the stack 
// When the expression is ended, the number in the stack is the final answer     

#include<bits/stdc++.h>
using namespace std;

// Stack type

struct Stack
{
    int top;
    unsigned capacity;
    int* array;
};


// Stack Operations

struct Stack* createStack( unsigned capacity )
{
    struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));

    if (!stack) return NULL;

    stack->top = -1;
    stack->capacity = capacity;
    stack->array = (int*) malloc(stack->capacity * sizeof(int));

    if (!stack->array) return NULL;

    return stack;
}

int isEmpty(struct Stack* stack)
{
    return stack->top == -1;
}

char peek(struct Stack* stack)
{
    return stack->array[stack->top];
}

char  pop(struct Stack* stack)
{
    if (isEmpty(stack)) return '$';
    return stack->array[stack->top--];
}

void push(struct Stack* stack, char op)
{
    if (stack->top == stack->capacity - 1) return;
    stack->array[++stack->top] = op;
}

// function to evaluate postfix expression

int evaluatePostfix(char*exp)
{

    // create a stack of capacity equal to the length of the expression

    struct Stack *stack = createStack(strlen(exp));

    // see if the stack was created successfully or not

    if (!stack)
        return -1;

    // scan the characters one by one

    for (int i = 0;i<strlen(exp);i++)
    {
        // if the scanned character is an operand (number here), push it to the stack

        if (isdigit(exp[i]))
            push(stack, exp[i] - '0');

        // if the scanned character is an operator, pop two elements from stack apply the operands

        else
        {
            int num2 = pop(stack);
            int num1 = pop(stack);

            switch (exp[i])
            {
                case '+':
                    push(stack, num1 + num2);
                    break;

                case '-':
                    push(stack, num1 - num2);
                    break;

                case '*':
                    push(stack, num1 * num2);
                    break;

                case '/':
                    push(stack, num1 / num2);
                    break;
            }
        }
    }
    return pop(stack);
}

// Time Complexity: O(N) 
// Auxiliary Space: O(N)


// It supports only 4 binary operators ‘+’, ‘*’, ‘-‘ and ‘/’. It can be extended for more operators by adding more switch cases. 
// The allowed operands are only single-digit operands. The program can be extended for multiple digits by adding a separator-like space between all elements (operators and operands) of the given expression. 


// Stack type

class Stack
{
    public:
    int top;
    unsigned capacity;
    int* array;
};

// Stack Operations

Stack* createStack( unsigned capacity )
{
    Stack* stack = new Stack();

    if (!stack) return NULL;

    stack->top = -1;
    stack->capacity = capacity;
    stack->array = new int[(stack->capacity * sizeof(int))];

    if (!stack->array) return NULL;

    return stack;
}

int isEmpty(Stack* stack)
{
    return stack->top == -1 ;
}

int peek(Stack* stack)
{
    return stack->array[stack->top];
}

int pop(Stack* stack)
{
    if (!isEmpty(stack))
        return stack->array[stack->top--] ;
    return '$';
}

void push(Stack* stack,int op)
{
    stack->array[++stack->top] = op;
}

// The main function that returns value
// of a given postfix expression

int evaluatePostfix(char* exp)
{
    // Create a stack of capacity equal to expression size
    Stack* stack = createStack(strlen(exp));
    int i;

    // See if stack was created successfully
    if (!stack) return -1;

    // Scan all characters one by one
    for (i = 0; exp[i]; ++i)
    {

        //if the character is blank space then continue

        if(exp[i] == ' ') continue;

        // If the scanned character is an
        // operand (number here),extract the full number
        // Push it to the stack.

        else if(isdigit(exp[i]))
        {
            int num = 0;

            // extract full num

            while(isdigit(exp[i]))
            {
                num = num * 10 + (int)(exp[i] - '0');
                i++;
            }
            i--;

            // push the element in the stack

            push(stack, num);
        }

        // If the scanned character is an operator, pop two
        // elements from stack apply the operator

        else 
        {
            int val1 = pop(stack);
            int val2 = pop(stack);
            switch (exp[i])
            {
                case '+':
                    push(stack, val2 + val1);
                    break;
                case '-':
                    push(stack, val2 - val1);
                    break;
                case '*':
                    push(stack, val2 * val1);
                    break;
                case '/':
                    push(stack, val2 / val1);
                    break;
            }
        }
    }
    return pop(stack);
}



// Evaluation of Postfix Expression
// EasyAccuracy: 53.28%Submissions: 41426Points: 2
// Given string S representing a postfix expression, the task is to evaluate the expression and find the final value. Operators will only include the basic arithmetic operators like *, /, + and -.



// Example 1:

// Input: S = "231*+9-"
// Output: -4
// Explanation:
// After solving the given expression, 
// we have -4 as result.
// Example 2:

// Input: S = "123+*8-"
// Output: -3
// Explanation:
// After solving the given postfix 
// expression, we have -3 as result.

// Your Task:
// You do not need to read input or print anything. Complete the function evaluatePostfixExpression() that takes the string S denoting the expression as input parameter and returns the evaluated value.


// Expected Time Complexity: O(|S|)
// Expected Auixilliary Space: O(|S|)


// Constraints:
// 1 ≤ |S| ≤ 105

// 0 ≤ |Si|≤ 9 (And given operators)


class Solution
{
    public:

    int evaluatePostfix(string S)
    {
        stack<int> stk;
        for (int i = 0; i < S.length();i++)
        {
            if(S[i]>='0'&&S[i]<='9')
            {
                stk.push(S[i] - '0');
            }
            else
            {
                int val1 = stk.top();
                stk.pop();
                int val2 = stk.top();
                stk.pop();
                switch(S[i])
                {
                    case '+':
                        stk.push(val2 + val1);
                        break;
                    case '-':
                        stk.push(val2 - val1);
                        break;
                    case '*':
                        stk.push(val2 * val1);
                        break;
                    case '/':
                        stk.push(val2 / val1);
                        break;
                }
            }
        }
        return stk.top();
    }

};