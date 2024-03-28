/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode
    {
    public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val)
        {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
int count=0;

int height(TreeNode<int> *root){

  if (root == NULL) {

    return 0;

  }

   int count1=height(root->left) + 1;

   int count2=height(root->right) + 1;

   return max(count1,count2);

}

int heightOfBinaryTree(TreeNode<int> *root)

{

   if (!root)
        return 0;
    return 1 + max(heightOfBinaryTree(root->left), heightOfBinaryTree(root->right));

    int maximum=height(root);

    return maximum;

}
