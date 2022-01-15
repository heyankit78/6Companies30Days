   vector<vector<int> > fourSum(vector<int> &arr, int k) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        set <vector<int>> s;
        for (int i=0; i<n; i++)
        {
            for (int j=i+1; j<n; j++)
            {
                int start = j+1;
                int end = n-1;
                while (start < end)
                {
                    ll sum = (ll)arr[i]+(ll)arr[j]+(ll)arr[start]+(ll)arr[end];
                    if (sum == k)
                    {
                        vector<int> temp = {arr[i], arr[j], arr[start], arr[end]};
                        s.insert(temp);
                        start++;
                        end--;
                    }
                    else if (sum > k)
                    {
                        end--;
                    }
                    else 
                    {
                        start++;
                    }
                }
            }
        }
            vector<vector<int>> ans (s.begin(), s.end());
            return ans;
    }
