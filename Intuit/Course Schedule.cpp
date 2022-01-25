class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<int>adj[numCourses];
        vector<int>indegree(numCourses,0);
        for(auto it : prerequisites){
            adj[it[1]].push_back(it[0]);
            indegree[it[0]]++;
        }
        queue<int>q;
        
        for(int i=0;i<numCourses;i++){
            if(indegree[i] == 0)
                q.push(i);
        }
        vector<int>ans;
        int count = 0;
        while(!q.empty()){
            ans.push_back(q.front());
            int node = q.front();
            q.pop();
            
            for(auto it : adj[node]){
                indegree[it]--;
                if(indegree[it] == 0)
                    q.push(it);
            }
            count++;        
        }
        vector<int>dummy;
        return count == numCourses ? ans : dummy;
    }
};
