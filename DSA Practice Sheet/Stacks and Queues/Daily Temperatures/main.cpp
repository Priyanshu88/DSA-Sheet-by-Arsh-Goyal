// 739. Daily Temperatures
// Medium

// 8088

// 177

// Add to List

// Share
// Given an array of integers temperatures represents the daily temperatures, return an array answer such that answer[i] is the number of days you have to wait after the ith day to get a warmer temperature. If there is no future day for which this is possible, keep answer[i] == 0 instead.

 

// Example 1:

// Input: temperatures = [73,74,75,71,69,72,76,73]
// Output: [1,1,4,2,1,1,0,0]
// Example 2:

// Input: temperatures = [30,40,50,60]
// Output: [1,1,1,0]
// Example 3:

// Input: temperatures = [30,60,90]
// Output: [1,1,0]
 

// Constraints:

// 1 <= temperatures.length <= 105
// 30 <= temperatures[i] <= 100
// Accepted
// 460,982
// Submissions
// 683,107


// Observation:

// For a temperature at index i, we need to find the slightly warmer temperature (at position j ) than the current temperature for 0 <= i < j < n. Which means we need to find the next greater element for the current element at index i and if not found then we place 0 in that place.

// Next Greater Element is a standard problem that is done by using stack and here we just have a slight variation in it. Instead of finding the next greater element, we need to find the distance between current element (temperature) and the next greater element which can be esily done.

// My Appraoch:

// We will keep a stack and we will start iterating from the end of the temperatures vector (n-1).

// Now, our main objective is to keep the candidate temperatures on the stack that can be a next greater temperature for current index. (It will become more clear when you'll read more below).

// Now, for a current temperature at index i, we will see the top of the stack and check whether it is greater than current element or not. Why we do this? Because stack is a LIFO and we came from right, so the top of the stack will be the latest element/temperature, that would have been pushed into the stack from the right of current index i so here can be two cases:

// Case 1: When this temperature at top of stack is less than the current temperature, then this can never be a next greater element of current temperature or all the other temperatures before current temperature. Why? Because for temperatures before current temperature (at position < i), temperature at current index can be their candidate for the next greater element. Hence we will simply pop the top of the stack out until we find an element greater than the current index or until the stack gets empty (This, means no greater element on the right).

// Case 2: When this temperature at top of the stack is greater than the current then we will simply consider this element as our next greater element and set the distance between the current temperature and next greater element/temperature as our answer for current index.

// After all this is done, then we will have either 0 or the distance between the current temp and next greater temp in the answer vector. Then we will simply push our current element into the stack as now this temp can be a candidate to become the next greater element for the temperatures before this temperature. And then move to the left (iteration goes on like this)

// Note: I may write nge for next greater element.

// Dry Run: Suppose our temperatures is like this:
// Iteration 1:

// nge vector = [0, 0, 0, 0, 0, 0, 0, 0] // initially all set to 0
// [73,74,75,71,69,72,76,73]
// 					  👆(starting position in the iteration)
// Now, our stack is empty that means we don't have anything greater than 73, now we push 73 in our stack and we move left.

// Iteration 2:

// nge vector = [0, 0, 0, 0, 0, 0, 0, 0]
// stack = [73] <- top
// [73,74,75,71,69,72,76,73]
// 				   👆(current position in iteration)
// Now, we will check the top of stack until we find the next greater element for 76, but 73 is smaller and after we pop stack then stack gets empty, that means we don't have anything greater than 76 to the right of current index. We will simply push 76 to the stack and move left (since this can be a candidate now).

// Iteration 3:

// nge vector = [0, 0, 0, 0, 0, 0, 0, 0]
// stack = [76] <- top
// [73,74,75,71,69,72,76,73]
// 				👆(current position in iteration)
// Now we check the top of our stack which is 76 and it is greater than 72, so we do not pop it and take it as our next greater element for 72. We then push current temperature to the stack and move left.

// Iteration 4:

// nge vector = [0, 0, 0, 0, 0, 76, 0, 0]
// stack = [76, 72] <- top
// [73,74,75,71,69,72,76,73]
// 			 👆(current position in iteration)
// Now, we check the top of the stack which is 72 and it is greater than 69, so we do not pop it and take it as our next greater element for 69. We then push current temperature to the stack and move left.

// Iteration 5:

// nge vector = [0, 0, 0, 0, 72, 76, 0, 0]
// stack = [76, 72, 69] <- top
// [73,74,75,71,69,72,76,73]
// 		  👆(current position in iteration)
// Now, we check while the top of the stack is less than or equals to current temp 71 that is we pop it from the stack, so 69 get popped out and we get 72 as our next greater element/temperature. So we take it, and push current temperature to stack and move left.

// Iteration 6:

// nge vector = [0, 0, 0, 72, 72, 76, 0, 0]
// stack = [76, 72, 71] <- top
// [73,74,75,71,69,72,76,73]
// 	   👆(current position in iteration)
// Now, we pop top of the stack till we found our next greater element for 75 and hence 71 and 72 gets popped out in the process, so we get 76 as our next greater element for 75 and then we push current temperature to the stack and move left.

// Iteration 7:

// nge vector = [0, 0, 76, 72, 72, 76, 0, 0]
// stack = [76, 75] <- top
// [73,74,75,71,69,72,76,73]
// 	👆(current position in iteration)
// Now the top of stack 75 is greater than 74, so it is our next greater element of our current temperature, so we take it and push current temperature to the stack and move left.

// Iteration 8:

// nge vector = [0, 75, 76, 72, 72, 76, 0, 0]
// stack = [76, 75, 74] <- top
// [73,74,75,71,69,72,76,73]
//  👆(current position in iteration)
// Now the top of the stack 74 is greater than 73, so we take it as our next greater element and push current temperature to the stack and move left.

// Iteration Complete: Now the iteration is completeed and we have:

// nge vector = [74, 75, 76, 72, 72, 76, 0, 0]
// stack = [76, 75, 74, 73] <- top
// [73,74,75,71,69,72,76,73]
// So our temperatures array and next greater element array looks like this, so the answer array will be just the distance between the current temperature and the next greater element of current temperature

// temperatures = [73, 74, 75, 71, 69, 72, 76, 73]
// next greater = [74, 75, 76, 72, 72, 76, 0, 0]
// ans vector   = [1,1,4,2,1,1,0,0]
// Note: For distance, we will push the index of temperatures in our stack so that we can calculate distance at the same time in the iterations.

#include<bits/stdc++.h>
using namespace std;



class Solution {
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        stack<int> stk;
        vector<int> ans;
        int n = temperatures.size() - 1;
        for (int i = n; i >= 0;i--)
        {
            if(stk.empty())
            {
                stk.push(i); //pushing the index
                ans.push_back(0);
            }
            else
            {

                // if we see that the current element in the stack is smaller than we pop the elements indeces

                while(!stk.empty() && temperatures[stk.top()]<=temperatures[i])
                {
                    stk.pop();
                }
                if(stk.empty())
                {
                    stk.push(i);
                    ans.push_back(0);
                }
                else
                {
                    ans.push_back(stk.top() - i);
                    stk.push(i);
                }
            }

        }

        // as we have answers in reverse order

        reverse(ans.begin(), ans.end());
        return ans;
    }
};


    class Solution
    {
    public:
        vector<int> dailyTemperatures(vector<int> &temperatures)
        {
            int n = temperatures.size();
            vector<int> NGE(n, 0); // initially all 0, stores distance between their next greater element and current temperature
            stack<int> st{};

            // move from right to left

            for (int i = n - 1; i >= 0; i--)
            {

                // pop until we find next greater element to the right
                // since we came from right stack will have element from right only
                // s.top() is the index of elements so we put that index inside temperatures vector to check

                while (!st.empty() && temperatures[st.top()] <= temperatures[i])
                {
                    st.pop();
                }

                // if stack not empty, then we have some next greater element,
                // so we take distance between next greater and current temperature
                // as we are storing indexes in the stack

                if (!st.empty())
                {
                    NGE[i] = st.top() - i; // distance between next greater and current
                }

                // push the index of current temperature in the stack,
                // same as pushing current temperature in stack

                st.push(i);
            }
            return NGE;
        }
};


// Time Complexity: O(N) Since we move from right to left, and the inner while loop stack only visit each temperature of the temperatures vector only once in all the iterations, so it's O(N) time complexity (You can observe from dry run)
// Space Complexity: O(N)


class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        int n = temperatures.size();
        int hottest = INT_MIN;
        vector<int> ans(n, 0);
        for (int i = n - 1; i >= 0;i--)
        {

            // if it is max temp. store it

            if(temperatures[i] >= hottest)
            {
                hottest = temperatures[i];
            }

            // otherwise take the iterator add keep on adding the value to the answer which we have already stored until we find the particular value

            else
            {
                int it = i + 1;
                while(temperatures[it] <= temperatures[i])
                {
                    it = it + ans[it];
                }
                ans[i] = it - i;
            }
        }
        return ans;
    }
};