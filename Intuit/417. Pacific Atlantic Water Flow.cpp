class Solution {
public:
    void solve(vector<vector<int>>&grid,int i,int j,int prev,vector<vector<int>>&sea){
        int n = grid.size();
        int m = grid[0].size();
        if(i<0 || i>=n || j<0 || j>=m)return;
        if(sea[i][j] == 1)return;
        if(grid[i][j] < prev){
            return;
        }
        else{
            sea[i][j] = 1;
            solve(grid,i+1,j,grid[i][j],sea);
            solve(grid,i-1,j,grid[i][j],sea);
            solve(grid,i,j+1,grid[i][j],sea);
            solve(grid,i,j-1,grid[i][j],sea);           
        }
        
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& grid) {
        
        vector<vector<int>>ans;
        int n = grid.size();
        if(n==0)return ans;
        int m = grid[0].size();
        vector<vector<int>>paci(n,vector<int>(m,0));
        vector<vector<int>>atla(n,vector<int>(m,0));
        
        for(int i=0;i<m;i++){
            solve(grid,0,i,INT_MIN,paci);
            solve(grid,n-1,i,INT_MIN,atla);
        }
        for(int i=0;i<n;i++){
            solve(grid,i,0,INT_MIN,paci);
            solve(grid,i,m-1,INT_MIN,atla);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(paci[i][j] == 1 && atla[i][j]==1){
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
        
    }
};
