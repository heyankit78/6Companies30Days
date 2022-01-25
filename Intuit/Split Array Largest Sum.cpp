class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int n= nums.size();
        long long int sum=0;
        if(n<m)return -1;
        for(int i=0;i<n;i++)sum+=nums[i];
        int start = 0;
        int end = sum;
        int res = -1;
        while(start<=end){
            int mid = (start + ((end-start)/2));
            if(is_valid(nums,n,m,mid)==true){
                res = mid;
                end = mid-1;
            }else{
                start = mid+1;
            }
        }
        return res;
    }
        bool is_valid(vector<int>& nums,int n,int m,int midx){
        int student = 1;
        long long int sum =0;
        for(int i=0;i<n;i++){
            if(nums[i] > midx)return false;
            if(sum + nums[i]>midx){
                student++;
                sum=nums[i];
                if(student > m)return false;
            }
            else{
                sum+=nums[i];
            }
    }
    return true;
    }
};
