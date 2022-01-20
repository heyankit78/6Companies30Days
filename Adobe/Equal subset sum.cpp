class Solution {
public:
    int dp[201][20001];
    bool canPartition(vector<int>& nums) {
        int total = 0;
        memset(dp,-1,sizeof(dp));
        for(auto c : nums)total+=c;
        
        if(total % 2!=0)return false;
        else
            return subset_sum(nums,total/2,nums.size());
    }
    bool subset_sum(vector<int>&nums,int target,int n){
        if(n<=0 or target<=0)
            return target == 0;
        if(dp[n][target]!=-1)
            return dp[n][target];
        if(nums[n-1]>target)
            return dp[n][target]=subset_sum(nums,target,n-1);
        else
            return dp[n][target]=subset_sum(nums,target,n-1) || subset_sum(nums,target-nums[n-1],n-1);
    }
};
