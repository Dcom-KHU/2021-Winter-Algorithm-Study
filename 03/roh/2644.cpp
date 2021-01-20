#include<iostream>
#include<vector>
//lca(least common ancestor) 문제는 사실... log(n) 해결방법이 있습니다...... 

using namespace std;

//각노드의 부모의 인덱스를 저장하는 배열
int parent[1000];


//child가 final ancestor 에 도달할때까지의 방문하는 노드의 idx를 돌려준다.
vector<int> get_p(int child){
  vector<int> result;
  while(child != -1){
    result.push_back(child);
    child = parent[child];
  }
  return result;
}

int main(){
  ios::sync_with_stdio(false);

  for(int i =0 ;i<1000; i++){
    parent[i] = -1;
  }

  int n_people;
  cin>>n_people;

  int target_a, target_b;
  cin>>target_a>>target_b;

  int n_rule;
  cin>>n_rule;

  while(n_rule--){
    int c,p;
    cin>>p>>c;
	  //트리를 만들어 줍니다!
	  //c번 노드의 부모는 p
    parent[c] = p;
  }

	//a,b 가 final ancestor 까지 가려면 누구를 거쳐가야하는지 저장하는 리스트(벡터)
  vector<int> a_parents = get_p(target_a);
  vector<int> b_parents = get_p(target_b);
	//만약 두 노드의 final ancestor 가 다르면 둘은 서로다른 트리에 존재하는것임.
  if(a_parents.back() != b_parents.back()){
    cout<<-1;
  }
  else{
	  //둘의 모든 공통된 조상들을 제외하고나면 그들이 최초로 공통되는 조상까지의 거리가 나온다.
    while(!a_parents.empty() && !b_parents.empty() && a_parents.back() == b_parents.back()){
      a_parents.pop_back();
      b_parents.pop_back();
    }
    cout<<a_parents.size() + b_parents.size();
  }
  return 0;
}