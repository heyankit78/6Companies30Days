

class Solution {
    public int compareVersion(String ver1, String ver2) {
    int n=ver1.length();
        int m=ver2.length();
        int r1=0,r2=0,l1=0,l2=0;
        while(r1<n || r2<m){
            int tmp1=0,tmp2=0;
            while(r1<n && ver1.charAt(r1)!='.') r1++;
            while(r2<m && ver2.charAt(r2)!='.') r2++;
            if(r1<=n) tmp1=Integer.parseInt(ver1.substring(l1,r1));
            if(r2<=m) tmp2=Integer.parseInt(ver2.substring(l2,r2));
            if(tmp1<tmp2) return -1;
            else if(tmp1>tmp2) return 1;
            r1++;
            r2++;
            l1=r1;
            l2=r2;
        }
        return 0;    
    }
}
