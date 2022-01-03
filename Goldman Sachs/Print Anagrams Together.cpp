
class Solution{
  public:
    vector<vector<string> > Anagrams(vector<string>& string_list) {
        //code here
        map<string,vector<string>>mp;
        for(auto l : string_list){
            string t = l;
            sort(t.begin(),t.end());
            mp[t].push_back(l);
        }
        vector<vector<string>>ans;
        for(auto c : mp){
            ans.push_back(c.second);
        }
        return ans;
    }
};
