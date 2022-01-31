class Solution {
public:
    int dp[501][501];
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        memset(dp,-1,sizeof(dp));
        return solve(piles,0,n-1,true);
    }
    int solve(vector<int>& piles,int start,int end,bool alice){
        if(start>=end)return 0;
        
        if(dp[start][end])
            return dp[start][end];
        
        if(alice){
            int op1 = solve(piles,start+1,end,false)+piles[start];
            int op2 = solve(piles,start,end-1,false)+piles[end];
            
            dp[start][end] = max(op1,op2);
        }
        else{
             int op1 = solve(piles,start+1,end,false)+piles[start];
            int op2 = solve(piles,start,end-1,false)+piles[end];
            
            dp[start][end] = max(op1,op2);
        }
        return dp[start][end];
    }
};
