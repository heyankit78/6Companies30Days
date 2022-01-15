class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    int FindMaxSum(int arr[], int n)
    {
        // Your code here
        int dp[n];
        if(n==1)return arr[0];
        if(n==2)return max(arr[0],arr[1]);
        
        dp[0] = arr[0];
        dp[1] = max(arr[0],arr[1]);
        
        for(int i=2;i<n;i++){
            dp[i] = max(arr[i]+dp[i-2],dp[i-1]);
        }
        return dp[n-1];
    }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
	int t;
	cin>>t;
	while(t--)
	{
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}
  /
