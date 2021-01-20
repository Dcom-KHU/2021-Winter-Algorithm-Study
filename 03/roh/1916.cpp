//1916
#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321
using namespace std;

//다익스트라 알고리즘은 그냥 해결하면 v^2
//priority_queue 사용시 v log v 로 해결가능합니다.
//dijkstra 아조씨는 v^2 알고리즘을 제시했었다고 하네요...?
//TMI 다익스트라 아저씨는 이 알고리즘을 가족이랑 여행중에 떠올렸고... 돌아오자마자 논문써서 발표했댑니다. 변태인가...?
//저는 p_q 사용하는 알고리즘으로 작성했습니다.


//시작노드로부터 해당 노드까지 거리를 저장할 곳.
int dist[20001];

int main() {
  //초기화
  ios::sync_with_stdio(false);
  for(int i =0;i<20001; i++)
    dist[i] = INF;
  //vertex와 edge의 개수를 받아줍니다.
  int n_v, n_e;
  cin>>n_v>>n_e;
	
  vector<pair<int,int>> graph[20001];
	//graph[a]에 <weight,b> 형태로 저장합니다.
  while(n_e--){
    int w,a,b;
    cin>>a>>b>>w;
    graph[a].push_back({w,b});
  }
  	//다익스트라는 계속 자신이 갈수 있는 그 다음으로 가장 가까운 곳을 찾습니다.
	//priority_queue를 이용해서 삽입시 log v 사출시 1의 시간복잡도로 갈 수 있는 가장 가까운 곳을 찾을 수 있습니다.
  priority_queue<pair<int,int>, vector<pair<int,int>>, std::greater<pair<int,int>>> q;
	//위 문장은 priority_queue<pair<int,int>>로... 사용하고 싶으면
	//weight값을 음수로 바꿔서 진행하시면 됩니다.
  int strt;
  cin>>strt;
	//나 자신까지는 0(?) 걸립니다.
  dist[strt] = 0;
	//시작점으로 부터 갈 수 있는 모든 곳을 queue에 넣습니다.
  for(auto& walker : graph[strt]){
    q.push(walker);
  }
	//q가 빌때까지 돌아 봅시다(?)
  while(!q.empty()){
	  //시작점에서 도착점까지 갈 수 있는 방법을 2번개째 찾았다면 그는 최적해가 아닙니다. 왜 why??
	  //방문하지 않은 모든 점 중에서, 지금 갈 수 있는 가장 가까운 점을 찾기 때문이죠.
    if(dist[q.top().second] == INF){
		//찾은 점 까지의 거리를 저장해줍니다.
      dist[q.top().second] = q.top().first;
		//찾은 점 부터 출발해서 갈 수 있는 모든 점들을 q에 넣어줍니다.
      for(auto& walker : graph[q.top().second]){
		  //단 이미 가는 방법을 찾은 점은 넣지 않습니다.
        if(dist[walker.second] == INF){
          q.push({walker.first+dist[q.top().second], walker.second});
        }
      }
    }
    q.pop();
  }
  int dest;
  cin>>dest;
  cout<<dist[dest];
}