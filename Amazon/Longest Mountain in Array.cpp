

class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size();
        int longi = 0;
        int temp = 0;
         int count;
        for(int i=1;i<=n-2;i++){
          
            if(arr[i] > arr[i-1] and arr[i]>arr[i+1]){
                int j = i;
                count = 1;
                while(j>0 and arr[j]>arr[j-1]){
                    j--;
                    count++;
                }
                 j = i;
                while(j<n-1 and arr[j]>arr[j+1]){
                    j++;
                    count++;
                }
            }
            longi = max(longi,count);
            count = 0;
        }
        return longi;
    }
};
