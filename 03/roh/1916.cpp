#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321
using namespace std;

int dist[20001];

struct myComp { 
    bool operator()( pair<int, int>& a, pair<int, int>& b) 
    { 
      if(a.second == b.second)
        return a.second < b.second; 
      return a.first < b.first;
    } 
}; 
int main() {
  ios::sync_with_stdio(false);
  for(int i =0;i<20001; i++)
    dist[i] = INF;
  int n_v, n_e;
  cin>>n_v>>n_e;
  vector<pair<int,int>> graph[20001];
  while(n_e--){
    int w,a,b;
    cin>>a>>b>>w;
    graph[a].push_back({w,b});
  }
  
  priority_queue<pair<int,int>, vector<pair<int,int>>, std::greater<pair<int,int>>> q;
  int strt;
  cin>>strt;
  dist[strt] = 0;
  
  for(auto& walker : graph[strt]){
    q.push(walker);
  }

  while(!q.empty()){
    //cout<<q.top().first<< ' '<<q.top().second<<endl;
    if(dist[q.top().second] == INF){
      dist[q.top().second] = q.top().first;
      for(auto& walker : graph[q.top().second]){
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