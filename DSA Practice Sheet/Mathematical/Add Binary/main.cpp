class Solution {
public:
    string addBinary(string a, string b) 
    {
        string output = "";
        int i = a.length()-1;
        int j = b.length()-1;
        int carry  = 0;
        while(i >= 0 || j >= 0 || carry)
        {
            if(i >= 0 && a[i--] == '1') carry++;
            if(j >= 0 && b[j--] == '1') carry++;
            output.insert(0,carry%2 == 1 ? "1":"0");
            carry /= 2;                    
        }
        return output;
    }
};