#include <iostream>
#include <string>

using namespace std;

//a의 길이는 b의 길이보다 작거나 같다.

int main() {
  string a,b;
  cin>>a>>b;
  
  //b에 a를 슬라이딩 시키며 최대로 많이 겹치는 순간을 찾는다.
  int large = -1;//가장 많이 겹칠때 얼마나 겹치는지 저장
  for(int shift = 0; shift <= b.size()-a.size(); shift++){
    int cur_max = 0;//shift부터 shift+b.size() 까지 비교했을때 얼마나 겹치는지 저장
    for(int walker = 0; walker < a.size(); walker++){
      if(a[walker] == b[shift+walker]){
        cur_max++;
      }
    }
	//cur_max의 최댓값 즉 가장많이 겹쳤을때 얼마나 겹쳤는지 저장.
    large = cur_max > large ? cur_max : large;
  }
  //어차피 앞뒤로 똑같은 거만 붙을거니까 해당 구간에서 다른게 몇개나 있는지만 찾으면됨.
  cout<<a.size() - large;
  return 0;
}