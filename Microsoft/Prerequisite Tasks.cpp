class Solution {
public:
	bool isPossible(int num, vector<pair<int, int> >& preq) {
	    // Code here
	   vector<vector<int>>adj(num);
        vector<int>indeg(num,0);
        queue<int>q;
        
        for(auto a: preq){
            adj[a.second].push_back(a.first);
            indeg[a.first]++;    
        }
        for(int i=0;i<num;i++){
            if(indeg[i]==0)
                q.push(i);
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto it : adj[node]){
                indeg[it]--;
                if(indeg[it]==0)q.push(it);
            }
            num--;
        }
        if(num==0)return true;
        return false;
	}
};
