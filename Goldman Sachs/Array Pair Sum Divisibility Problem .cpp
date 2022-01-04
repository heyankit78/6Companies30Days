


class Solution {
  public:
    bool canPair(vector<int> arr, int k) {
        // Code here.
        map<int,int>mp;
        int n = arr.size();
        if(n % 2!= 0)return false;
        for(auto p : arr){
            mp[(p % k+ k)%k]++;  // to handle negative cases
        }
        // for(auto c : mp)cout<<c.first<<"->"<<c.second<<endl;
        if(mp[0]%2 ==1)return false;
        for(int i=1;i<k;i++){   
            if(mp[i]!=mp[k-i])
                return false;
        }
        return true;
    
    }
};
