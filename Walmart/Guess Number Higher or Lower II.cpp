class Solution {
public:
    int dp[201][201];
    int helper(int start,int end){
        if(start>=end)return 0;
        if(dp[start][end]!=-1)return dp[start][end];
        int res = INT_MAX;
        for(int i=start;i<=end;i++){
            int temp = i;
            temp+=max(helper(start,i-1),helper(i+1,end));
            res = min(res,temp);
        }
        dp[start][end] = res;
        return res;
    }
    int getMoneyAmount(int n) {
        memset(dp,-1,sizeof(dp));
        return helper(1,n);
    }
};
