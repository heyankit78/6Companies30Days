

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        if(n==0)return 0;
        int cnt = 0;
        int row = grid.size();
        int col = grid[0].size();
        int empty = 0;
        queue<pair<int,int>>q;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j] == 0)empty++;
                if(grid[i][j] == 2)
                    q.push({i,j});
            }
        }
        int dx[] = {-1,0,+1,0};
        int dy[] = {0,+1,0,-1};
        int days = 0;
        while(!q.empty()){
            int k = q.size();
            cnt +=k;
            while(k--){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for(int i=0;i<4;i++){
                    int newx = x + dx[i];
                    int newy = y + dy[i];
                    if(newx < 0 || newy < 0 || newx >= row || newy >= col || grid[newx][newy] != 1)continue;
                    grid[newx][newy] = 2;
                    q.push({newx,newy});
                }
            }
            if(!q.empty())days++;
        }
        int size = row*col;
        return empty+cnt == size ? days : -1;
    }
};
