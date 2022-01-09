

class Solution {
  public:
    int maxi = 0;
     void kdown(Node* root,Node* block,int timee){
        if(root == nullptr || root == block){
            return;
        }
        // if(k == 0){
        //     path.push_back(root->val);
        //     return;
        // }
        // int maxi = 0;
        maxi = max(maxi,timee);
        kdown(root->left,block,timee+1);
        kdown(root->right,block,timee+1);
        
    }
    int dist(Node* root,int target){
        if(root == nullptr)return -1;
        if(root->data == target){
            kdown(root,nullptr,0);
            return 1;
        }
        int left_time = dist(root->left,target);
        if(left_time!=-1){
            kdown(root,root->left,left_time);
            return left_time+1;
        }
 
        int right_time = dist(root->right,target);
        if(right_time!=-1){
            kdown(root,root->right,right_time);
            return right_time+1;
        }
        return -1;
    }
    int minTime(Node* root, int target) 
    {
        // Your code goes here
        dist(root,target);
        return maxi;
    }
};
