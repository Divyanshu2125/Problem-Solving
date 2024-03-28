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
    void helper(TreeNode* root, int targetSum,vector<vector<int>>& ans,vector<int>& temp)
{
    if(root ==NULL)return;
    temp.push_back(root->val);
    if(root->left==NULL && root->right==NULL && targetSum==root->val)
     ans.push_back(temp);
    helper(root->left,targetSum-root->val,ans,temp);
     helper(root->right,targetSum-root->val,ans,temp);
     temp.pop_back();
} 
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
       vector<vector<int>> ans;
       vector<int> temp;
       helper(root,targetSum,ans,temp);
       return ans; 
    }
};
