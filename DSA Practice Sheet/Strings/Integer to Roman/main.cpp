class Solution {
public:
    string intToRoman(int num) 
    {
        string ones[] = {"","I","II","III","IV","V","VI","VII","VIII","IX"};
        string tens[] = {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
        string hundreds[] = {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
        string thousands[] = {"","M","MM","MMM"};
    }

    // 2982
    // 2982/1000 = 2 => MM, 2982%1000 = 982/100 = 9 => CM, 2982%100 = 82/10 = 8 => LXXX, 2892%10 = 2 => II
    
    return thousands[num/1000] + hundred[(num%1000)/100] + tens[(num%100)/10] + ones[num%10];
};