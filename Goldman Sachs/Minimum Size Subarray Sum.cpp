class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i = 0;
        int j = 0;
        int n = nums.size();
        int sum = 0;
        int mini = INT_MAX;
        while(j<n){
            if(sum < target){
                sum+=nums[j];
            }
            if(sum >=target){               
                while(i<=j && sum >= target){
                    sum-=nums[i];
                    mini = min(mini,j-i+1);
                    i++;
                }
            }
            j++;
        }
        return mini == INT_MAX ?  0: mini;
    }
};
