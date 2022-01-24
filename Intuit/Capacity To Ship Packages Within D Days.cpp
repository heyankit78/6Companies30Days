class Solution {
public:
    int shipWithinDays(vector<int>& w, int day) {
        int lo = *min_element(w.begin(),w.end());
        int hi = accumulate(w.begin(),w.end(),0);
        int ans = -1;
        int n = w.size();
        if(day > n)return -1;
        while(lo<=hi){
            int mid = lo+(hi-lo)/2;
            if(solve(w,mid,day)){
                ans = mid;
                hi = mid-1;
            }else{
                lo = mid+1;
            }
        }
        return ans;
        
    }
    bool solve(vector<int>&w,int mid,int day){
        int k = 1;
        int sum = 0;
        for(int i=0;i<w.size();i++){
            if(w[i]>mid)return false;
            sum+=w[i];
            if(sum>mid){
                k++;
                sum = w[i];
            }
        }
        return k<=day;
    }
};
