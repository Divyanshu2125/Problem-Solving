/*Complete the function below
Node is as follows:
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

class Solution
{
  public:
    //Function to convert binary tree into circular doubly linked list.
    Node *prev = NULL;
    Node *bToDLL(Node *root) {
        if(root == NULL) return root;
        Node *head = bToDLL(root -> left);
        if(prev == NULL) head = root;
        else {
            root -> left = prev;
            prev -> right = root;
        }
        prev = root;
        bToDLL(root -> right);
        return head;
    }
    Node *bTreeToCList(Node *root){
        Node *head = bToDLL(root);
        Node *tail = head;
        while(tail -> right != NULL) tail = tail -> right;
        tail -> right = head;
        head -> left = tail;
        return head;
    }
};
