

class Solution {
public:
    void solve(int open,int close,int n,string str,vector<string>&ans){
        if(open > n)
            return;
        else if(open == n and close == 0){
            ans.push_back(str);
            return;
        }   
        solve(open+1,close+1,n,str+"(",ans);
        if(close > 0)
            solve(open,close-1,n,str+")",ans);
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        solve(0,0,n,"",ans);
        return ans;
    }
};
