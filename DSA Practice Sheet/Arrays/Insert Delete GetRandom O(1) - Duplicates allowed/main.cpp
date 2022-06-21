class RandomizedCollection 
{
    private:

    // storing all the elements
    
    vector<int> nums;

    // to ensure O(1)
    
    unordered_map<int,unordered_set<int>> mp;

public:
    RandomizedCollection() 
    {
        
    }
    
    // insert value to end of array and insert index in set mp[val]
    // and return true if one val is present

    bool insert(int val) 
    {
        nums.push_back(val);
        int index = nums.size()-1;
        mp[val].insert(index);
        return mp[val].size() == 1;
    }
    
    // if the value is not present return 0 
    // get the value of 1st element of mp[val] and store it in index variable and erase the index from mp[val] set
    // if index of element is not equal to lastIndex then delete the lastIndex from mp[nums[lastIndex]] set and insert index into lastIndex then swap the values of index and lastIndex
    // delete the last element from nums
    
    bool remove(int val) 
    {
        if(!mp.count(val))
        return 0;
        int index = *(mp[val].begin());
        int lastIndex = nums.size()-1;
        mp[val].erase(index);
        if(index != lastIndex)
        {
            mp[nums[lastIndex]].erase(lastIndex);
            mp[nums[lastIndex]].insert(index);
            swap(nums[index],nums[lastIndex]);
        }
        nums.pop_back();

        // if the size of mp[val] is 0,
        // val is absent and has been removed

        if(mp[val].size() == 0)
        mp.erase(val);
        return 1;
    }

    // get any random index from 0 to nums.size()-2 and return the value at that index

    int getRandom()
    {
        int randomIndex = rand() % nums.size();

        return nums[randomIndex];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */