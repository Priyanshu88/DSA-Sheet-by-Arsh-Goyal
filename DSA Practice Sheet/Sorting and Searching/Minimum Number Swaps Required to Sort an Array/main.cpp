void Swap(vector<int> &arr, int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}



int Index_(vector<int> &arr, int ele)
{
    for(int i=0;i<arr.size();i++)
    {
        if(arr[i] == ele)
        {
            return i;
        }
    }
    return -1;
}


// Return the minimum number
// of swaps required to sort the array


int minSwaps(vector<int> arr, int n)
{
    int ans = 0;
    vector<int> temp(arr.begin(), arr.end());
    sort(temp.begin(), temp.end());

    for(int i=0;i<n;i++)
    {

        // This is checking whether
        // the current element is
        // at the right place or not

        if(arr[i] != temp[i])
        {
            ans++;

            // swaping the current element
            // with the right index
            // so that arr[0] to arr[i] is sorted

            swap(arr, i, Index_(arr, temp[i]));
        }
    }
    return ans;
}
// T.C. :O(n * n)
// S.C. :O(n)



int minSwaps(vector<int>& nums)
{

    int n = nums.size(); 

    // creating a list of pairs where first element of pair is array 
    // element and second element is its position

    vector<pair <int, int>> cur(n);

    // iterating over the array elements

    for(int i=0;i<n;i++)
    {

        // storing the elements and their position as pair in the list

        cur[i].first = nums[i];
        cur[i].second = i;
    }

    // sorting the list

    sort(cur.begin(), cur.end());

    // using boolean list to mark visited elements and currently 
    // marking all the nodes as false

    vector<bool> vis(n, false);

    int ans = 0;
    for(int i=0;i<n;i++)

    {

        // if element is already visited or it is already at
		// correct position, we continue the loop

        if(vis[i] || cur[i].second == i)
        continue;
        int cycle_size = 0;
        int j = i;

        // while element is not visited, we find out the number of nodes in
        // this cycle and keep incrementing cycle size

        while(!vis[j])
        {
            vis[j] = true;
            j = cur[j].second;
            cycle_size++;
        }

        // updating number of swaps required

        ans += (cycle_size > 1) ? cycle_size-1:0;
    }

    return ans;

}



// T.C. :O(n log n)
// S.C. :O(n)
