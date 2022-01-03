
class Solution{
  public:
    int countSubArrayProductLessThanK(const vector<int>& nums, int n, long long k) {
        long long start = 0;
        long long end = 0;
        long long count = 0;
        long long prod = 1;
        while(end < n){
            prod *= nums[end];
            
            while(start < n and prod>=k){
                prod/=nums[start];
                start++;
            }
            if(prod<k)count+=(end-start+1);
            end++;
            
        }
        return (long long)count;
    }
};
