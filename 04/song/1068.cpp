#include <iostream> 
#include <queue>
using namespace std;

#define DEACTIVATED -2
#define MAXNODE 50

int main()
{
	int node[MAXNODE];
	fill_n(node, MAXNODE, DEACTIVATED);

	int n; //n:노드의 개수
	cin >> n;

	//node 초기화 - 배열에 부모노드 저장
	for (int i = 0; i < n; i++)
	{
		int parent;
		cin >> parent;
		node[i] = parent;
	}

	int delNode; //삭제할 노드의 번호
	cin >> delNode;
	queue<int> q;
	q.push(delNode);
	//선택한 노드 및 하위 노드 비활성화
	while (!q.empty())
	{
		delNode = q.front();
		q.pop();
		node[delNode] = DEACTIVATED; //자기자신 비활성화
		for (int i = 0; i < n; i++)
		{
			if (node[i] == delNode) //자식이 있는 경우
			{
				//자식노드를 q에 push 이후 비활성화
				q.push(i);
				node[i] = DEACTIVATED;
			}
		}
	}
	//리프노드 확인 - node[]에서 자신을 가리키는 대상 없을 경우 리프노드
	bool isLeafNode[MAXNODE];
	fill_n(isLeafNode, MAXNODE, true);
	for (int i = 0; i < n; i++)
	{
		if (node[i] == -1) //i번째 node가 루트노드일 경우
			continue; //리프노드 여부 판별 불가
		else if (node[i] != DEACTIVATED) //i번째 node가 부모를 가지고 있으면서 루트노드가 아닐 경우
			isLeafNode[node[i]] = false; //해당 부모노드는 리프노드가 아님
		else  //i번째 node가 비활성화된 경우
			isLeafNode[i] = false; //해당 노드는 리프노드가 아님
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