class Solution {
public:
    bool winnerOfGame(string col) {
        int cnta = 0;
        int cntb = 0;
        int cnt = 0;
        for(int i=0;i<col.size();i++){
            if(col[i] == 'A')cnt++;
            else{
                if(cnt >= 3)
                    cnta += (cnt-2);
                cnt = 0;            
            }
        }
           if(cnt >= 3)
                    cnta += (cnt-2);
                cnt = 0;
        cnt = 0;
        for(int i=0;i<col.size();i++){
            if(col[i] == 'B')cnt++;
            else{
                if(cnt >= 3)
                    cntb += (cnt-2);
                cnt = 0;            
            }
        }
           if(cnt >= 3)
                    cntb += (cnt-2);
                cnt = 0;
        // if(cnta == cntb)return false;
        return cnta > cntb ? true : false;
    }
};
