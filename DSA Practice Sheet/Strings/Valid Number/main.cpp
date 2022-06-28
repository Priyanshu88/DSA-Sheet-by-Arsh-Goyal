class Solution {
public:
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
            // e/E or if i is at last index return false 
            // else increase count of plus_minus

            else if(s[i] == '+' || s[i] == '-')
            {
                if(plus_minus == 2 || (i>0 && (s[i-1] != 'e' && s[i-1] != 'E')) || i == n-1) return false;
                plus_minus++;
            }

            // e, E check 
            else if(s[i] == 'e' || s[i] == 'E')
            {
                if(e_E || !digit || i == n-1) return false;
                e_E = true;
            }
            else if(s[i] == '.')
            {
                if(e_E || dot || (i == n-1 && !digit)) return false;
                dot = true;
            }
            
            else
            {
                return false;
            }
        }
        return true;
    }
};