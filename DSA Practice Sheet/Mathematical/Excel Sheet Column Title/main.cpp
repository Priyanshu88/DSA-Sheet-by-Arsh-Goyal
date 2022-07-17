class Solution {
public:

    // If we take (n-1)%26 where n is the columnNumber and we are mapping as 0 to 'A' likewise till 25 to 'Z', and the expression 
    // if we add to the ASCII value of 'A' then we get the ASCII value of resulting character at last digit, for second last digit 
    // we will keep appending this to the beginning of the result as it will be initially empty when we calculated the last character
    // we append it into the beginning and again we map the ranged values with same approach and get as (n-1)/26 at the place of n and
    // we keep doing this until n becomes 0 where n is the columnNumber.

// expressions: char ch = (columnNumber-1)%26;
// columnNumber = (columnNumber-1)/26;

    string convertToTitle(int columnNumber) 
    {
        string result = "";
        while(columnNumber)
        {
            char c = 'A' + (columnNumber - 1)%26;
            result = c + result;
            columnNumber = (columnNumber - 1)/26;
        }
        return result;
    }
};