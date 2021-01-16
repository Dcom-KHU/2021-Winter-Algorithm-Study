#include<iostream>
#include<string>

using namespace std;

int main(){
  string input;
  cin>>input;
  
  for(int i = 0; i < input.size()/2; i++){
    //앞에서 부터 i 번째 문자와 뒤에서부터 i번째를 비교합니당.
    if(input[i] != input[input.size()-1-i]){
      cout<<0;
      return 0;
    }
  }
  //위의 if문에 걸리지 않으면 펠린드롬임.
  cout<<1;

  return 0;
}