#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321
using namespace std;

int p[1001];

//다익스트라 알고리즘은 그냥 해결하면 v^2        priority_queue 사용시 v log v 로 해결가능합니다.
//dijkstra 아조씨는 v^2 알고리즘을 제시했었다고 하네요...?
//TMI 다익스트라 아저씨는 이 알고리즘을 가족이랑 여행중에 떠올렸고... 돌아오자마자 논문써서 발표했댑니다. 변태인가...?

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
  while(n_e--){
    int a,b,w;
    cin>>a>>b>>w;
    q.push(make_pair(w,make_pair(a,b)));
  }

  int cnt = 0;
  while(!q.empty()){
	  //두개의 점이 같은 set에 속해있는 확인해야 해당 가중치를 선택할지 말지 여부를 확인 할 수 있습니다.
    int p_a = get_p(q.top().second.first);
    int p_b = get_p(q.top().second.second);
    if(p_a != p_b){
      cnt+=q.top().first;
      if(p_a < p_b)
        p[p_b] = p_a;
      else
        p[p_a] = p_b;
    }
    q.pop();
  }
  cout<<cnt;
}