
class Solution {
public:
     bool cmp(string &s1,string s2){
        if(s1.size()!=s2.size()){
            return s1.size() < s2.size();
        }
        return s1 < s2;
    }
    string kthLargestNumber(vector<string>& nums, int k) {
        
        sort(nums.begin(),nums.end(),cmp);
        priority_queue<string>pq;
        for(auto p : nums){
            pq.push(p);
        }
        while(k>1){
            pq.pop();
            k--;
        }
        return pq.top();
    }
};
