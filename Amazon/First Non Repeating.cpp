class Solution {
	public:
		string FirstNonRepeating(string a){
		    // Code here
		    vector<int>vis(26,0);
		    vector<char>v;
		    string ans = "";
		    for(int i=0;i<a.size();i++){
		        if(!vis[a[i]-'a']){
		            v.push_back(a[i]);
		        }
		        vis[a[i]-'a']++;
		        int flag = 0;
		        int m = v.size();
		        for(int j=0;j<m;j++){
		            if(vis[v[j]-'a'] == 1){
		                ans.push_back(v[j]);
		                flag = 1;
		                break;
		            }
		        }
		        if(flag==0){
		            ans.push_back('#');
		        }
		    }
		    return ans;    
		}
};
