#include <iostream>

using namespace std;

struct Node {
	int value;
	Node *left;
	Node *right;
};

void postOrder(Node *node);
Node* insert(int value, Node *root);

int main() {
	int num;
	Node *root=NULL;

	while (cin >> num)
		root = insert(num, root);
	
	postOrder(root);
}

void postOrder(Node *node) {
	if (node->left != NULL)
		postOrder(node->left);
	if (node->right != NULL)
		postOrder(node->right);
	cout << node->value << '\n';
}

Node* insert(int value, Node *root) {
	if (root == NULL) {
		root = new Node();
		root->value = value;
	}
	else if (value < root->value)
		root->left = insert(value,root->left);
	else
		root->right = insert(value,root->right);

	return root;
}