class Solution {
public:
    int kthFactor(int n, int k) 
    {
        //check whether i is a factor of n or not if it is then wwe subtract k by one as soon as k reaches to 0 we return will return that factor as kth factor
        // otherwise return -1
        
        for(int i=1;i<=n;i++)
        {
            if(n%i == 0 && --k == 0)
            return i;
        } 
        return -1;
    }
};




// If i is the factor of n then n/i will be the factor of n as well 
// and we get this uptil square root of n for the first half and 
// for the second half we get the factor iterating from square root 
// of n to 1 and returning the value as n/i



class Solution {
public:
    int kthFactor(int n, int k) 
    {
        for(int i=1;i*i<=n;i++)
        {
            if(n%i == 0 && --k == 0)
            {
                return i;
            }
        }

        for(int i*i=n;i>=1;i--)
        {
            if(n%i == 0 && --k == 0)
            {
                return n/i;
            }
        }
        return -1;

    }
};