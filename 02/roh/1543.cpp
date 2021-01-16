#include <iostream>
#include <string>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  string a,b;
  getline(cin,a);
  getline(cin,b);
  int cnt = 0; 

  //아래 if문안넣어서 제출 10번함 띠용..
  if(a.size() >= b.size())
  for(int shift = 0; shift <= a.size() - b.size(); shift++){
    for(int walker = 0 ; walker <= b.size(); walker++){
      //마지막 인덱스 그 뒤에 도달시 성공
      if(walker == b.size()){
        cnt++;
        shift += b.size()-1;
        break;
      }
      //index out of range 방지.. 필요한가?
      if(shift+walker >= a.size())
        break;
      //둘이 다를경우 break
      if(b[walker] != a[shift+walker]){
        break;
      }
    }
  }
  cout<<cnt;
  return 0;

}