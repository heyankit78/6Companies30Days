
class Solution
{
  public:
    //Function to find maximum of each subarray of size k.
    vector <int> max_of_subarrays(int *arr, int n, int k)
    {
        // your code here
        vector<int>ans;
        int i = 0;
        int j = 0;
        list<int>l;
        int mx = INT_MIN;
        if(k>n){
            ans.push_back(*max_element(arr,arr+n));
            return ans;
        }
        while(j<n){
            while(!l.empty() && l.back() < arr[j]){
                l.pop_back();
            }
            l.push_back(arr[j]);
            if(j-i+1 < k)j++;
            else if(j-i+1 == k){
                ans.push_back(l.front());
                if(l.front() == arr[i])l.pop_front();
                i++;
                j++;
            }
        }
        return ans;
    }
};
