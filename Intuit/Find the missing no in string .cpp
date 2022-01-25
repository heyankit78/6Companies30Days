#include<bits/stdc++.h> 
using namespace std; 

int len = 0;

int getValue(char str[], int i, int m) 
{ 
    if (i + m > len) 
        return -1; 

    int value = 0; 
    for (int j = 0; j < m; j++) 
    { 
        int c = str[i + j] - '0'; 
        if (c < 0 || c > 9) 
            return -1; 
        value = value * 10 + c; 
    } 
    return value; 
} 

int findMissingNumber(char str[]) 
{ 
    for (int m=1; m<=6; ++m) 
    { 
        int n = getValue(str, 0, m); 
        if (n == -1) 
        break; 

        int missingNo = -1; 

        bool fail = false; 

        for (int i=m; i!=len; i += 1 + log10l(n)) 
        { 
            if ((missingNo == -1) && 
                (getValue(str, i, 1+log10l(n+2)) == n+2)) 
            { 
                missingNo = n + 1; 
                n += 2; 
            } 

            else if (getValue(str, i, 1+log10l(n+1)) == n+1) 
                n++; 

            else
            { 
                fail = true; 
                break; 
            } 
        } 

        if (!fail) 
        return missingNo; 
    } 
    return -1;
} 

int main() 
{ 
    int test;
    cin>test;

    while(test--){

        char str[1001];
        cin>str;

        len = strlen(str);

        cout<<findMissingNumber(str)<<endl;

    }
}
