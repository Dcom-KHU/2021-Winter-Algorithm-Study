#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long init(vector<long long>& a, vector<long long>& tree, int node, int start, int end) {
	if (start == end) {
		return tree[node] = a[start];
	}
	else {
		return tree[node] = init(a, tree, node * 2, start, (start + end) / 2) + init(a, tree, node * 2 + 1, (start + end) / 2 + 1, end);
	}
}

long long sum(vector<long long>& tree, int node, int start, int end, int left, int right) {
	if (left > end || right < start) {
		return 0;
	}
	if (left <= start && end <= right) {
		return tree[node];
	}
	return sum(tree, node * 2, start, (start + end) / 2, left, right) + sum(tree, node * 2 + 1, (start + end) / 2 + 1, end, left, right);
}

void update(vector<long long>& tree, int node, int start, int end, int index, long long diff) {
	if (index < start || index > end) return;
	tree[node] = tree[node] + diff;
	if (start != end) {
		update(tree, node * 2, start, (start + end) / 2, index, diff);
		update(tree, node * 2 + 1, (start + end) / 2 + 1, end, index, diff);
	}
}

int main() {
	vector<long long> vec(10);
	vector<long long> tree(32);

	for (int i = 0; i < 10; i++)
	{
		cin >> vec[i];
	}

	init(vec, tree, 1, 0, 9);
	cout << "2 ~ 5 번째 까지: " << sum(tree, 1, 0, 9, 1, 4) << endl;

	update(tree, 1, 0, 9, 3 - 1, 3);  // 3번째 원소 (+3)
	cout << "2 ~ 5 번째 까지: " << sum(tree, 1, 0, 9, 1, 4) << endl;
}