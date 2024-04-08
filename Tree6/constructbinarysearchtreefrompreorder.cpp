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
    TreeNode* bstFromPreorder(vector<int>& preorder) {      
        TreeNode *root = new TreeNode(preorder[0]);
        TreeNode *p = root;
        stack<TreeNode*> S;
        int i = 1;
        while(i < preorder.size())
        {
            if(p->val > preorder[i])
            {
                p->left = new TreeNode(preorder[i]);
                S.push(p);
                p = p->left;
            }
            else
            {
                while(!S.empty() && S.top()->val < preorder[i])
                {
                    p = S.top();
                    S.pop();
                }
                p->right = new TreeNode(preorder[i]);
                p = p->right;
            }
            i++;
        }
        return root;
    }
};
