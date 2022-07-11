class Solution {
    public:
    bool isPalindrome(int x)
    {

        // reversing half of the int number
        // when x < 0, x is not a palindrome
        // Also if the last digit of the number is 0,
        // the first digit of the number also needs to be 0
        // Only 0 satisfy this property
        // When the length is an odd number, we can get rid of the middle digit by revertedNumber/10
        // since the middle digit doesn't matter in palindrome(it will always equal to itself), simply get rid of it

        if(x < 0 || (x % 10 == 0 && x != 0))
        {
            return false;
        }
        int reverseNum = 0;
        while(x > reverseNum)
        {
            reverseNum = reverseNum * 10 + x % 10;
            x /= 10;
        }
        return x == reverseNum || x == reverseNum/10;
    }
};