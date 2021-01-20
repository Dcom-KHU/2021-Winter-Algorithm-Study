#include<iostream>
#define INF 1000000001
using namespace std;

int graph[101][101];

//플로이드 워셜 알고리즘으로 풀기


//기본적인 그래프를 초기화해준다.
void init(){
  for(int i =0 ;i<101; i++) for(int j = 0; j<101; j++){
    graph[i][j] = INF;
    if(i == j) graph[i][j] = 0;
  }
}

int main(){
  ios::sync_with_stdio(false);
  init();

  int n_city;
  cin>>n_city;

  int n_bus;
  cin>>n_bus;

  //point 1 : 시작점과 도착점이 같은 엣지가 2개이상 존재가능. 해당경우 최소 가중치를 가진 엣지사용.
  while(n_bus--){
    int strt, end, cost;
    cin>>strt>>end>>cost;
    graph[strt][end] = min(cost, graph[strt][end]);
  }

  //stopover = 경유지
  //꼭 포문을 stopover가 가장 밖에 있도록 써야하는데... 이유가 뭘까...?
	//머리를 쓰면 알겠지만 쓰기싫다... 
  for(int stopover = 1; stopover<=n_city; stopover++){
    for(int strt = 1; strt <= n_city; strt++){
      for(int end = 1; end <= n_city; end++){
        //변수명이... 너무긴가...? 
		int best = graph[strt][end];
        int strt_stopover = graph[strt][stopover];
        int stopover_end = graph[stopover][end];
        
        if(strt_stopover < INF && stopover_end < INF){
          best = min(best, strt_stopover + stopover_end);
          graph[strt][end] = best;
        }
      }
    }
  }
	//출력하는 코드
  for(int i =1 ;i<=n_city; i++){
    for(int j = 1; j<=n_city; j++){
		//못가는 구간 및 자기자신으로 가는 구간은 0이출력되어야함... 이것때매 3번 제출함.. 나는 바보야...
      if(graph[i][j] >= INF)
        cout<<0<<' ';
      else
        cout<<graph[i][j]<< ' ';
    }
    cout<<'\n';
  }
}