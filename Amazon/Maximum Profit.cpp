class Solution {
  public:
      int dp[501][2][201];
    int solve(int i,bool own,int price[],int k,int j,int n){
        if(i == n || j>=k)
            return 0;
        if(dp[i][own][j]!=-1)return dp[i][own][j];
        // int ans = 0;
       if(own){
            int op1 = price[i]+solve(i+1,0,price,k,j+1,n);
            int op2 = solve(i+1,1,price,k,j,n);
            return dp[i][own][j] = max(op1,op2);
        
        }else{
            int op1 = -price[i]+ solve(i+1,1,price,k,j,n);
            int op2 = solve(i+1,0,price,k,j,n);
            return dp[i][own][j] = max(op1,op2);   
        }
    }
    int maxProfit(int K, int N, int A[]) {
        // code here
        if(N == 0)return 0;
        memset(dp,-1,sizeof(dp));
        return solve(0,0,A,K,0,N);
    }
};
