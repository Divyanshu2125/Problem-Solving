class Solution {
    void solver(vector<int>& ans, TreeNode *root, int l = 1)
    {
        if (!root)
        {
            return;
        }
        if (l > ans.size())
        {
            ans.push_back(root->val);
        }
        l++;
        solver(ans, root->right, l);
        solver(ans, root->left, l);
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        solver(ans, root);
        return ans;
    }
};
