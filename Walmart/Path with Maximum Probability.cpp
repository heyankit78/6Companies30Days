class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succ, int start, int end) {
        vector<vector<pair<int,double>>>adj(n);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back({edges[i][1],succ[i]});
            adj[edges[i][1]].push_back({edges[i][0],succ[i]});
        }
        vector<double>res(n,0.0);
        res[start] = 1.0;
        
        priority_queue<pair<double,int>>pq;
        pq.push({1.0,start});
        
        while(!pq.empty()){
            auto prob = pq.top().first;
            auto node = pq.top().second;
            pq.pop();
            for(auto &it : adj[node]){
                auto i = it.first;
                auto p = it.second;
                
                if(res[i] < prob*p){
                    res[i] = prob*p;
                    pq.push({res[i],i});
                }
            }
            
        }
        return res[end];  
    }
};
