

class Solution
{
	public:
	bool flag = false;
    //Function to find if the given edge is a bridge in graph.
    void dfs(int node,int parent,vector<int>&vis,vector<int>adj[],vector<int>&low,vector<int>&tin,int timer,int c,int d){
        
        vis[node]=parent;
        tin[node]=low[node]=timer++;
        for(auto it : adj[node]){
            if(it == parent)continue;
            
            if(!vis[it]){
                dfs(it,node,vis,adj,low,tin,timer,c,d);
                low[node] = min(low[node],low[it]);
                if(tin[node] < low[it]){
                    if(node == c && it == d || node == d && it == c)flag = true;
                }
            }
            else{
                low[node]=min(low[node],tin[it]);
            }
        }
    }
    int isBridge(int n, vector<int> adj[], int c, int d) 
    {
   
        vector<int>low(n,-1);
        vector<int>tin(n,-1);
        vector<int>vis(n,0);
        int timer = 0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,-1,vis,adj,low,tin,timer,c,d);
            }
        }
        if(flag)return 1;
        else return 0;
    }
