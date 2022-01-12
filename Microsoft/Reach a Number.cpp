class Solution {
public:
    int reachNumber(int target) {
        target = abs(target);
        int sum = 0;
        int i=0;
        while(sum<target){
            i++;
            sum+=i;  
        }
        if(sum==target)return i;
        while((sum-target) % 2!=0){
            i++;
            sum+=i;
        }
        return i;
    }
};
