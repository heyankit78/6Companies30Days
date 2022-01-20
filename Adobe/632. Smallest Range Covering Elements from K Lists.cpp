class Solution {
public:
    class elem{
        public:
        int value;
        int index;
        int row;
        int arrsize;
        
        elem(int val,int ind,int row_number,int arr_n){
            value = val;
            index = ind;
            row = row_number;
            arrsize = arr_n;
        }
    };
    struct cmp{
        bool operator()(elem a,elem b){
            return a.value > b.value;
        }
    };
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int n = nums.size();
        priority_queue<elem,vector<elem>,cmp>q;
        int low,high;
        int mn = INT_MAX;
        int mx = INT_MIN;
        
        for(int i=0;i<n;i++){
            q.push(elem(nums[i][0],0,i,nums[i].size()));
            mn = min(mn,nums[i][0]);
            mx = max(mx,nums[i][0]);
        }
        int range = INT_MAX;
        while(!q.empty()){
            elem temp = q.top();
            q.pop();
            int may_be = temp.value;
            if(range > mx - may_be){
                mn = may_be;
                range = mx - mn;
                low = mn;
                high = mx;             
            }
            
            if(temp.index == temp.arrsize-1){
                break;
            }
            temp.index+=1;
            q.push(elem(nums[temp.row][temp.index],temp.index,temp.row,nums[temp.row].size()));
            mx = max(mx,nums[temp.row][temp.index]);
        }
        vector<int>v{low,high};
        return v;
          
    }
};
