


class Solution {
public:
    string decode(string s,int &i){
        string ans = "";
        
        while(i<s.size() and s[i]!=']'){
            
            if(!isdigit(s[i]))
                ans+=s[i++];
            else{
                int n = 0;
                while(i<s.size() and isdigit(s[i])){
                    n = n*10+s[i++] - '0';
                }
                i++; // [
                string t = decode(s,i);   
                while(n--){
                    ans+=t;
                }
                i++; // ] 
            }
        }
        return ans;
    }
    string decodeString(string s) {
        int i =0;
        return decode(s,i);
    }
};
