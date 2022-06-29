class Solution {
public:
    vector<string> ones = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    vector<string> tens = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    string integer2string(int num)
    {
        string temp1;
        if(num >= 100)
        {
            temp1 += ones[num/100] + " Hundred" + " ";
            num = num % 100;
        }
        
        if(num >= 20)
        {
            temp1 += tens[num/10] + " ";
            num = num % 10;
        }

        if(0 < num && num < 20)
        {
            temp1 += ones[num] + " ";
        }
        return temp1;
    } 


    string numberToWords(int num)
    {
        string temp2;

        if(num >= 1000000000)
        {
            temp2 += integer2string(num/1000000000) + "Billion" + " ";
            num = num % 1000000000;
        }
        if(num >= 1000000)
        {
            temp2 += integer2string(num/1000000) + "Million" + " ";
            num = num % 1000000;
        }
        if(num >= 1000)
        {
            temp2 += integer2string(num/1000) + "Thousand" + " ";
            num = num%1000;
        }
        if(num < 1000)
        {
            temp2 += integer2string(num);
        }
        if(temp2.length() == 0)  return "Zero";
        return temp2.substr(0,temp2.size()-1);
    }
};