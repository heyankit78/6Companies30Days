

class Solution{   
public:
    string printMinNumberForPattern(string s){
        // code here 
        stack<int>st;
        int num = 1;
        string ans;
        for(int i=0;i<s.size();i++){
            char ch = s[i];
            if(ch == 'D'){
                st.push(num);
                num++;
            }
            else{
                st.push(num);
                num++;
                while(!st.empty()){
                    ans += to_string(st.top());
                    st.pop();
                }
            }
            // st.clear();
        }
        st.push(num);
             while(!st.empty()){
                    ans += to_string(st.top());
                    st.pop();
                }
        return ans;
    }
};
