class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
    
    // Prefix Sum technique 

    int pref = 0;
    vector<int> preArr(k);

    // Base case

    preArr[pref]++;
    int answer = 0;
    for(int i=0;i<nums.size();i++)
    {

        // taking modulo and considering only positives

        pref = (pref+nums[i]) % k;

        if(pref < 0)  
            pref += k;
        answer += preArr[pref];

        // increment count

        preArr[pref]++;
    }
        return answer;
    }
};