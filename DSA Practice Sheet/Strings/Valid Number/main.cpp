class Solution {
public:

    // we check for invalid cases and end up with valid solution

    bool isNumber(string s) 
    {
        bool digit = false, dot = false, e_E = false;
        int plus_minus = 0, n = s.length();
        for(int i=0;i<n;i++)
        {

            // checking for digit to be valid
            // if found any digit then mark digit as true

            if(s[i]-'0' >= 0 && s[i]-'0' <=9)
            {
                digit = true;
            }

            // checking for sign if + or - is there and if plus_minus == 2  and i is not at starting index and the previous index does not have 
            // e/E or if i is at last index hence it is not valid so return false 
            // else increase count of plus_minus

            else if(s[i] == '+' || s[i] == '-')
            {
                if(plus_minus == 2 || (i>0 && (s[i-1] != 'e' && s[i-1] != 'E')) || i == n-1) return false;
                plus_minus++;
            }

            // e, E check 
            // if we already have one e/E or no digit found till now or i  is at last index then it is an invalid number so return false
            // otherwise assign e_E as true

            else if(s[i] == 'e' || s[i] == 'E')
            {
                if(e_E || !digit || i == n-1) return false;
                e_E = true;
            }

            // if there is e_E or dot again or i is at last index and no any digit is there then it is invalid number so return false
            // else assign true to dot

            else if(s[i] == '.')
            {
                if(e_E || dot || (i == n-1 && !digit)) return false;
                dot = true;
            }

            // if any above condition does not satisfy then also return false
            
            else
            {
                return false;
            }
        }

        // otherwise return true

        return true;
    }
};






// we check for invalid cases and end up with valid solution


class Solution {
public:
    bool isNumber(string S) 
    {
        bool digit = false, e_E =  false, plus_minus = false, dot = false;
        for(auto i: S)
        {

            // if you see any number between 0 to 9 assign true to digit

            if(i >= '0' && i <= '9') 
            {
                digit = true;
            }

            // ('e'/'E') has already appeared or seeing an 'e'/'E' when a number has not yet been seen.
            // return false
            // else assign true to e_E and  reset all flags except e_E when we find an 'e'/'E', as we're starting a new integer expression.

            else if(i == 'e' || i == 'E')
            {
                if(e_E || !digit) return false;
                else e_E = true, plus_minus = false, digit = false, dot = false;
            }

            // if one sign has already encountered or sign is after digit or after decimal then return false
            // else assign true to plus_minus
            
            else if(i == '+' || i == '-')
            {
                if(plus_minus || digit || dot) return false;
                else plus_minus = true;
            }

            // if decimal is more than one or decimal appearing after e/E  return false
            // else assign true to dot 

            else if(i == '.')
            {
                if(dot || e_E) return false;
                else dot = true;
            }
            else
            {
                return false;
            }
        }
        return digit;

    }
};   