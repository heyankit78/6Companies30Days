class Solution {
public:
    void swap(vector<int>&index, int i, int j){
        int temp = index[i];
        index[i] = index[j];
        index[j] = temp;
    }
    
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int>index(n);
        int i, j, k, l;
        for(i = 0; i < n; i++){
            k = 0;
            for(j = n - 1; j >= 0; j--){
                if(grid[i][j] == 0){
                    k++;
                }
                else{
                    break;
                }
            }
            index[i] = k;
        }
        int ans = 0;
        for(i = 0; i < n; i++){
            j = n - 1 - i;
            for(k = i; k < n; k++){
                if(index[k] >= j){
                    break;
                }
            }
            if(k == n){
                return -1;
            }
            else{
                for(l = k; l > i; l--){
                    swap(index, l, l - 1);
                }
                ans += k - i;
            }
        }
        return ans;
    }
};
