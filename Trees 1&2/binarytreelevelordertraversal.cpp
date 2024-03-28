class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
      queue<TreeNode *> q;
        q.push(root);
        vector<vector<int>> ans;
        if (!root)
            return ans;
        while (q.size())
        {
            int s = q.size();
            vector<int> t;
            while (s--)
            {
                TreeNode *f = q.front();
                q.pop();
                t.push_back(f->val);
                if (f->left)
                    q.push(f->left);
                if (f->right)
                    q.push(f->right);
            }
            ans.push_back(t);
        }
        return ans;
    }
};
