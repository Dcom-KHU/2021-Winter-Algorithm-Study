#include <iostream>
#include <string>
#include <vector>

using namespace std;

char flag = 'I';

//1. vector컨테이너 안에 IOI패턴이 몇번 반복되었는지 넣는다.
/*
EX) IOIOIOIIIIOIOIO -> [3,2]
EX) IIIOOOOIOIOIOIO -> [4]
*/
//2. 리스트 안에 IOI패턴의 길이에따라 P(N)을 몇번 넣을 수 있는지 나온다.
//2.A 이때 N보다 적은 반복횟수면 P(N)을 넣을 수 없다.
/*
EX) [3,2] N=2 -> (3-2+1) + (2-2+1)
EX) [4] N=3 -> (4-3+1)
*/
//내가 설명했지만...... 알아듣기 힘들어....

int main() {
  ios::sync_with_stdio(false);
  int n, m;
  vector<int> v;
  v.push_back(-1);
  cin >> n >> m;
  string target;
  cin >> target;
  for(int i = 0 ; i<target.size(); i++){
    if(target[i] == flag){
      if(flag == 'I') v.back() += 1;
      flag = (flag == 'I') ? 'O' : 'I';
    }
    else{
      if(v.back() != -1){
        if(v.back() == 0)
          v.back() -= 1;
        else
          v.push_back(-1);
      }
      if(target[i] == 'I'){
        v.back() += 1;
        flag = 'O';
      }
    }
  }
  int cnt = 0;
  for(auto& walker : v){
    if(walker-n >= 0)
      cnt+= walker-n+1;
  }
  cout<<cnt;
}