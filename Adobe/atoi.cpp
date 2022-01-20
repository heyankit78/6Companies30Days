

        long res = 0;
        bool flag = false;
        long i = 0;
        
        while(i<s.size() and s[i]==' ')i++;
 	    if(s[i]=='+') i++;
		else if(s[i]=='-'){
			flag=true;
			i++;
		}
        while(i<s.size()){
            if(s[i] >= '0' and s[i] <= '9'){
                res =(long long) res*10 +( s[i]-'0');
                if(res>=INT_MAX) break;
            }
            else
                break;
            i++;
        }
        if(flag)res*=-1;
        
        if(res<=INT_MIN) return INT_MIN;
		else if(res>=INT_MAX) return INT_MAX;
		return res;
