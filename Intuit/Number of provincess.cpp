class Solution {
public:
    vector<int>parent;
    int find_par(int node){
        if(parent[node] == node)return node;
        return parent[node] = find_par(parent[node]);
    }
    void union_size(int a,int b){
        int pu = find_par(a);
        int pv = find_par(b);
        
        if(pu != pv){
            parent[pv] = pu;
        }
    }
    int findCircleNum(vector<vector<int>>& grid) {
        int n = grid.size();
        parent.resize(n);
        
        for(int i=0;i<n;i++){
            parent[i] = i;
        }
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(grid[i][j] == 1){
                    union_size(i,j);
                }
            }
        }
        int count = 0;
        map<int,int>mp;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(grid[i][j] == 1){
                    if(find_par(i) == find_par(j) && mp.find(find_par(i)) == mp.end()){
                        count++;
                        mp[find_par(i)] = 1;
                    }
                }
            }
        }
        return count;
    }
};
