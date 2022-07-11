class Solution {
public:

    // if n is equal to 0 return false
    // taking modulo and dividing with 2 for every n
    // if n is equal to 1 at last then return true

    bool isPowerOfTwo(int n) {
        if(n == 0) return false;
        while(n % 2 == 0)  n /= 2;
        return n == 1;
    }
};

// T.C. :O(log n)


// the AND operation of n and n-1 will be 0 if n is the power of 2

class Solution {
public:
    bool isPowerOfTwo(int n) 
    {
        if(n <= 0) return false;
        return ((n&(n-1)) == 0);
    }
};

// T.C. : O(1)