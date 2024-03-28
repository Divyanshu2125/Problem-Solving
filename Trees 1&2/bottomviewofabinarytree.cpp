#include<bits/stdc++.h>
using namespace std;
struct Node
{
	int data; 
	int hd; 
	Node *left, *right;

  Node(int key)
	{
		data = key;
		hd = INT_MAX;
		left = right = NULL;
	}
};

void bottomView(Node *root)
{
	if (root == NULL)
		return;

  int hd = 0;
	map<int, int> m;
	queue<Node *> q;
	root->hd = hd;
	q.push(root); 

	while (!q.empty())
	{
		Node *temp = q.front();
		q.pop(); 
		hd = temp->hd;
		m[hd] = temp->data;
		if (temp->left != NULL)
		{
			temp->left->hd = hd-1;
			q.push(temp->left);
		}
		if (temp->right != NULL)
		{
			temp->right->hd = hd+1;
			q.push(temp->right);
		}
	}
	for (auto i = m.begin(); i != m.end(); ++i)
		cout << i->second << " ";
}
int main()
{
	Node *root = new Node(10);
	root->left = new Node(12);
	root->right = new Node(32);
	root->left->left = new Node(13);
	root->left->right = new Node(43);
	root->right->left = new Node(24);
	root->right->right = new Node(54);
	root->left->right->left = new Node(32);
	root->left->right->right = new Node(54);
	cout << "Bottom view of the given binary tree :\n";
	bottomView(root);
	return 0;
}
