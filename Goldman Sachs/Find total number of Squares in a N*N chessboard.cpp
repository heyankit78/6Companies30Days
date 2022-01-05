class Solution {
  public:
    long long squaresInChessBoard(long long n) {
        // code hern
        if(n==1)return n;
        long long ans = n*n;
        n--;
        while(n>0){
            ans+=n*n;
            n--;
        }
        return ans;
    }
};
