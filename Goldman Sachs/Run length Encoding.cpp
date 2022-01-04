

string encode(string s)
{     
  //Your code here 
  string ans = "";
  int i=0;
  int j=0;
  while(j<s.size()){
      while(s[i]==s[j]){
          j++;
      }
    ans += s[i] + to_string(j-i);
    i=j;
  }
  return ans;
}  
