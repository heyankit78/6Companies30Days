class Solution {
public:
    int mod = 1000000007;
    int maxPerformance(int n, vector<int>& speed, vector<int>& eff, int k) {
        vector<pair<int,int>>org;
        for(int i=0;i<n;i++){
            org.push_back({eff[i],speed[i]});
        }
        sort(org.rbegin(),org.rend());
        priority_queue<int,vector<int>,greater<int>>pq;
        long tot = 0;
        long ans = 0;
        for(int i=0;i<n;i++){
            int curr_speed = org[i].second;
            tot += curr_speed;
            pq.push(curr_speed);
            
            if(pq.size() > k){
                tot-=pq.top();
                pq.pop();
            } 
            ans = max(ans,tot*org[i].first);
        }
        ans%=mod;
        return ans;
    }
};
