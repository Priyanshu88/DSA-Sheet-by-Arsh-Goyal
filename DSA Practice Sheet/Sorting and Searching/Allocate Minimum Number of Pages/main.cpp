int minPages(int arr[], int n, int k)
{
    int sum = 0;
    int mx = 0;
    for(int i=0;i<n;i++)
    {
        sum += arr[i];
        mx = max(mx, arr[i]);
    }

    int low = mx;
    int high = sum;
    int res = 0;

    while (low <= high)
    {
        int mid = (low+high)/2;
        if(isFeasible(arr, n, k,mid));
        {
            res = mid;
            high = mid-1;
        }
        else
        {
            low = mid+1;
        }
        
    }
    

    return res;

}



bool isFeasible(int arr[], int n, int k, int ans)
{
    int req = 1, sum = 0;
    for(int i=0;i<n;i++)
    {
        if(sum+arr[i] > ans)
        {
            req++;
            sum = arr[i];
        }
        else
        {
            sum += arr[i];
        }
    }
    return (req <= k);
}







// checking if current minimum value is feasible or not

bool isFeasible(int arr[],int n, int m, long long int curMin)
{
    int strudentReq = 1;
    int cureSum = 0;

    // iterating over all books

    for(int i=0;i<n;i++)
    {

        // checking if current number of pages are greater
        // than curr_min that means we will br getting the result
        // after mid no. of pages

        if(arr[i] > curMin)
        return false;

        // counting how many students are required
        // to distribute curr_min pages

        if(cureSum + arr[i] > curMin)
        {

            // incrementing student count

            strudentReq++;

            // updating curr_sum

            cureSum = arr[i];

            // if students required becomes greater
            // than given no. of students then return false

            if(strudentReq > m) return false; 

        }

        // else update curr_sum

        else
        {
            cureSum += arr[i];
        }
    }
    return true;
}


// finding minimum pages

int findPages(int arr[], int n, int m)
{
    long long sum = 0;

    // return -1 if no. of books is less than
    // no. of students

    if(n < m) return -1;

    // Counting total number of pages

    for(int i=0;i<n;i++) sum += arr[i];

    // initializing start as 0 pages and end as
    // total pages

    long long start = 0;
    long long end = sum, mid;
    long long int ans = int(1e15);

    // traversing until start <= end

    while (start <= end)

    {

        // checking if it is possible to distribute
        // books by using mid as current minimum

        mid = (start + end)/2;

        if(isFeasible(arr,n,m,mid))
        {

            // updating result to current distribution
            // as it's the best we have found till now.

            ans = ans < mid ? ans:mid;

            // as we are finding minimum and books
            // are sorted so reduce end = mid -1
    

            end = mid-1;
        }

        else
        {

            // if not possible means pages should be
            // increased so update start = mid + 1

            start = mid + 1;
        }

    }

    // at last return minimum no. of  pages

    return ans;
    

}
