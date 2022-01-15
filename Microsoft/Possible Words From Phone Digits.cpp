void solve(int digits[],int n,int index,string output,vector<string>&ans,string arr[])
    {
        if(index==n)
        {
            ans.push_back(output);
            return;
        }
        int digit=digits[index];
        string temp=arr[digit];
        for(int i=0;i<temp.length();i++)
        {
            output.push_back(temp[i]);
            solve(digits,n,index+1,output,ans,arr);
            output.pop_back();
        }
            
        
        
    }
    vector<string> possibleWords(int a[], int N)
    {
        vector<string>ans;
        if(N==0)
            return ans;
        int index=0;
        string output="";
        string arr[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        solve(a,N,index,output,ans,arr);
        return ans;
    }
