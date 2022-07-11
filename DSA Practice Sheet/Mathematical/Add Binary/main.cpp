class Solution {
public:
    string addBinary(string a, string b) 
    {

        // maintaining string to store the value

        string output;

        // traversing both from the end

        int i = a.length()-1;
        int j = b.length()-1;

        // initializing carry as 0

        int carry = 0;

        // traversing till we reach first element

        while(i >= 0 || j>= 0)
        {

            // assigning carry to sum

            int sum = carry;

            // adding to after converting ASCII to int i.e. doing - 0 from the string
            
            if(i >= 0) sum+= a[i--]-'0';
            if(j >= 0) sum+= b[i--]-'0';

            // if sum is greater than 1, make carry as 1

            carry = sum > 1?1:0;
            
            // converting in binary as 1+1 = 2, 2%2=0 and adding it to output
            
            output += to_string(sum%2);
            
        }
        
        // if carry is there add it to carry,

        if(carry) output += to_string(carry); 

        // reverse the output string

        reverse(output.begin(),output.end());
    }

    return output;
};