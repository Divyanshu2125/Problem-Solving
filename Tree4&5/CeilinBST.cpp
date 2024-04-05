int findCeil(Node* root, int input) {
    if (root == NULL) return -1;
     
    int ans = -1;
    Node* temp = root;
    while(temp){
        if(temp->data >=input){
            if(temp->data == input) return input;
            ans = temp->data;
            temp = temp->left;
        }
        else temp = temp->right;
    }
    return ans;
