

 int *ans=new int[2];
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[arr[i]]++;
        }
       for(int i=1;i<n+1;i++){
           if(mp[arr[i]]>1){
               ans[0]=arr[i];
           }
       }
        for(int i=1;i<=n;i++){
            if(mp[i]==0){
                ans[1]=i;
                break;
            }
        }
        return ans;
