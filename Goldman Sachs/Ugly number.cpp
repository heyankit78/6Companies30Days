


class Solution{
public:	
	// #define ull unsigned long long
	/* Function to get the nth ugly number*/
	ull getNthUglyNo(int n) {
	    // code here
	    ull dp[n+1];
	    dp[1]=1;
	    int p2 =1;
	    int p3 = 1;
	    int p5 = 1;
	    
	    for(int i=2;i<=n;i++){
	        long long int f1 = 2*dp[p2];
	        long long int f2 = 3*dp[p3];
	        long long int f3 = 5*dp[p5];
	        
	        long long int mini=min({f1,f2,f3});
	        dp[i]=mini;
	        
	        if(mini == f1)p2++;
	        if(mini == f2)p3++;
	        if(mini == f3)p5++;
	    }
	    return (ull)dp[n];
	}
};
