#include <iostream>

using namespace std;

int tree[26][2];

void pre(int n) { // Preorder
	if (n == -1) 
		return;
	cout << char(n + 'A'); //�ڽ�

	pre(tree[n][0]); //����

	pre(tree[n][1]); //������
}

void in(int n) { // Inorder
	if (n == -1) 
		return;

	in(tree[n][0]); //����

	cout << char(n + 'A'); //�ڽ�

	in(tree[n][1]); //������
}

void post(int n) { // PostOrder
	if (n == -1) 
		return;

	post(tree[n][0]); //����

	post(tree[n][1]); //������

	cout << char(n + 'A'); //�ڽ�
}

int main() {
	ios::sync_with_stdio(false);
	int n; // ����� ����
	cin >> n;
	while (n--) {
		char node, left, right;

		cin >> node >> left >> right;

		if (left != '.') {
			tree[node - 'A'][0] = left - 'A';
		}
		else { // left == '.'
			tree[node - 'A'][0] = -1;
		}

		if (right != '.') {
			tree[node - 'A'][1] = right - 'A';
		}
		else { // right == '.'
			tree[node - 'A'][1] = -1;
		}
	}

	pre(0);
	cout << '\n';
	in(0);
	cout << '\n';
	post(0);
}