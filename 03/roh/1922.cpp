#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321
using namespace std;

/*
MST Minimum Spanning Tree 문제입니다.
가중치의 총합이 가장 작은, 모든 노드를 연결할 수 있는, 그래프를 찾는겁니다.
알분...때 하나...?
*/


//Union Find를 사용했습니다.
//특정 set안에 있는 모든 element는, 해당 set에서 가장 작은 숫자를 가진 idx를, p[i]에 저장하고 있습니다.
//만약 p[i] == -1 인 i가 있다면, 그 친구(?)는 자신이 속한 set에서 가장 작은 idx를 가진 것입니다.
int p[1001];

//해당 idx가 포함된 set에서, 가장 작은 idx값을 가진 element를 반환합니다.
int get_p(int child){
  if(p[child] != -1)
	  //아래 줄을 실행하면 get_p(p[child]) 값을 p[child] 에 저장하고 p[child]를 리턴합니다.
    return p[child] = get_p(p[child]);
  return child;
}

struct myComp { 
    bool operator()( pair<int, pair<int, int>>& a, pair<int, pair<int, int>>& b) 
    { 
      return a.first > b.first;
    } 
}; 


int main() {
  for(int i = 0; i<1001; i++)
    p[i] = -1;
  ios::sync_with_stdio(false);
	//데이터는 <가중치,<출발지, 도착지>> 형태로 저장하고
	//priority queue는 가중치 기준으로 정렬 합니다.
  priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>,myComp> q;
	
  int n_v,n_e;
  cin>>n_v>>n_e;
    //모든 edge를 queue에다 넣습니다.
  while(n_e--){
    int a,b,w;
    cin>>a>>b>>w;
    q.push(make_pair(w,make_pair(a,b)));
  }
	

  int cnt = 0;
  while(!q.empty()){
	  //두개의 점이 같은 set에 속해있는 확인해야 해당 엣지를 선택할지 말지 선택할 수 있습니다.
    int p_a = get_p(q.top().second.first);
    int p_b = get_p(q.top().second.second);
	  //두 점이 서로다른 set에 존재할경우
    if(p_a != p_b){
		//edge 가중치의 총합에 새로운 edge의 가중치를 더해주고
      cnt+=q.top().first;
		//두 set을 1개로 합쳐줍니다.
		//unionFind를 사용하면 이 과정이 다음과 같이 간편하게(?) 처리됩니다.
      if(p_a < p_b)
        p[p_b] = p_a;
      else
        p[p_a] = p_b;
    }
    q.pop();
  }
  cout<<cnt;
}