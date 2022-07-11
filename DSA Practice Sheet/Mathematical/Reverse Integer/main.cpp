class Solution {
public:
    int reverse(int x) 
    {

        // it is similar to standard reversing but the  statement rev = rev * 10 + last_digit can cause overflow. 
        // checking beforehand whether this statement would cause an overflow
        // assuming rev is positive.
        // If rev = rev * 10 + last_digit causes overflow, then it must be that rev ≥ INT_MAX/10
        // If rev > INT_MAX/10, then rev = rev*10+last_digit is guaranteed to overflow
        // if rev == INT_MAX/10, then rev - rev*10+last_digit will overflow if and only if last_digit > 7
​        // Similar logic can be applied when rev is negative
        // If rev = rev * 10 + last_digit causes overflow, then it must be that rev <= INT_MAX/10
        // If rev < INT_MAX/10, then rev = rev*10+last_digit is guaranteed to overflow
        // if rev == INT_MAX/10, then rev = rev*10+last_digit will overflow if and only if last_digit < -8
​        

        int rev = 0;
        while(x != 0)
        {
            int last_digit = x % 10;
            x /= 10;

            if(rev > INT_MAX/10 || (rev == INT_MAX/10 && last_digit > 7)) return 0;
            if(rev < INT_MAX/10 || (rev == INT_MAX/10 && last_digit < -8)) return 0;

            rev = rev*10+last_digit;
        }
        return rev;
    }
};