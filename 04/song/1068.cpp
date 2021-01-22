#include <iostream> 
#include <queue>
using namespace std;

#define DEACTIVATED -2
#define MAXNODE 50

int main()
{
	int node[MAXNODE];
	fill_n(node, MAXNODE, DEACTIVATED);

	int n; //n:����� ����
	cin >> n;

	//node �ʱ�ȭ - �迭�� �θ��� ����
	for (int i = 0; i < n; i++)
	{
		int parent;
		cin >> parent;
		node[i] = parent;
	}

	int delNode; //������ ����� ��ȣ
	cin >> delNode;
	queue<int> q;
	q.push(delNode);
	//������ ��� �� ���� ��� ��Ȱ��ȭ
	while (!q.empty())
	{
		delNode = q.front();
		q.pop();
		node[delNode] = DEACTIVATED; //�ڱ��ڽ� ��Ȱ��ȭ
		for (int i = 0; i < n; i++)
		{
			if (node[i] == delNode) //�ڽ��� �ִ� ���
			{
				//�ڽĳ�带 q�� push ���� ��Ȱ��ȭ
				q.push(i);
				node[i] = DEACTIVATED;
			}
		}
	}
	//������� Ȯ�� - node[]���� �ڽ��� ����Ű�� ��� ���� ��� �������
	bool isLeafNode[MAXNODE];
	fill_n(isLeafNode, MAXNODE, true);
	for (int i = 0; i < n; i++)
	{
		if (node[i] == -1) //i��° node�� ��Ʈ����� ���
			continue; //������� ���� �Ǻ� �Ұ�
		else if (node[i] != DEACTIVATED) //i��° node�� �θ� ������ �����鼭 ��Ʈ��尡 �ƴ� ���
			isLeafNode[node[i]] = false; //�ش� �θ���� ������尡 �ƴ�
		else  //i��° node�� ��Ȱ��ȭ�� ���
			isLeafNode[i] = false; //�ش� ���� ������尡 �ƴ�
	}
	int leafNodeCnt = 0;
	for (int i = 0; i < n; i++)
	{
		if (isLeafNode[i])
			leafNodeCnt++;
	}
	cout << leafNodeCnt;
	return 0;
}