


class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int start = 1;
        int end = *max_element(piles.begin(),piles.end());
        int ans;
        while(start <= end){
            int mid = (start + end)/2;
            if(can_possible(piles,mid,h) == true){
                ans = mid;
                end = mid-1;
            }
            else{
                start = mid+1;
            }
        }
        return ans;
    }
    bool can_possible(vector<int>&piles,int mid,int h){
        int hour = 0;
        for(int i=0;i<piles.size();i++){
            int val = (piles[i])/mid + (piles[i] % mid == 0 ? 0 : 1);
            hour+=val;
        }
        return hour<= h;
    }
};
