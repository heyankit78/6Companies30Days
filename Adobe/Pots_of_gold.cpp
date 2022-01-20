// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    int solve(vector<int>&v,vector<vector<int>>&dp,int start,int end){
        
        if(start>end)return dp[start][end] = 0;
        if(start == end)dp[start][end] = v[start];
        if(dp[start][end] != -1)return dp[start][end];
        int op1 = v[start] + min(solve(v,dp,start+2,end),solve(v,dp,start+1,end-1));
        
        int op2 = v[end] + min(solve(v,dp,start+1,end-1),solve(v,dp,start,end-2));
        
        dp[start][end] = max(op1,op2);
    }
    int maxCoins(vector<int>&A,int n)
    {
	    //Write your code here
	    vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
	    return solve(A,dp,0,n-1);
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int>A(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        Solution ob;
        cout << ob.maxCoins(A, N) << "\n";
    }
    return 0;
}
  // } Driver Code Ends vector<vector<int>>dp
