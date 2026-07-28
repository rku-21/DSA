/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
  
    int MAX=INT_MAX;
    int MIN=INT_MIN;
      int maxseen=MIN;
    pair<int,int> solve(TreeNode* root){
         if(!root) return {-1,-1};

         auto left=solve(root->left);
         auto right=solve(root->right);
         
         int maxi=MIN;
         int mini=MAX;
         maxi=max({left.first,left.second,right.first,right.second});
         if(maxi==-1) return {root->val,root->val};
        
         
         if(left.first==-1) left.first=MAX;
         if(left.second==-1) left.second=MAX;
         if(right.first==-1) right.first=MAX;
         if(right.second==-1) right.second=MAX;
         mini=min({left.first,left.second,right.first,right.second});
        

         maxseen=max({maxseen,abs(root->val-maxi),abs(root->val-mini)});
         return {max(root->val,maxi),min(root->val,mini)};
    }
    int maxAncestorDiff(TreeNode* root) {
        solve(root);
        return maxseen;

        
    }
};