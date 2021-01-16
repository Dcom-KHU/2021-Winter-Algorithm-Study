#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> primes;
vector<int> p_primes;
//p = palindrome

//팰린드롬인지 확인
bool is_p(int target){
  string str = to_string(target);
  for(int i = 0; i<str.size()/2; i++){
    if(str[i] != str[str.size()-1-i])
      return false;
  }
  return true;
}

//prime 여부확인
//sqrt(target) 이하의 모든 prime으로 나누어본다.
bool is_prime(int target){
  for(auto& walker : primes){
    if(target % walker == 0)
      return false;
    if(target < walker*walker)
      return true;
  }
  return true;
}

//primes 배열과 p_primes 배열을 만든다.
//100만 이상의 최초 p_prime 은 1003001이지만 모른다 치고
//적당히 200만 넣었다.

//에라토스테네슨가 에라스토테네슨가 그거쓰면 좀더 빠름.
void init(){
  primes.push_back(2);
  p_primes.push_back(2);
  for(int i = 3 ; i<2000000; i+=2){
    if(is_prime(i)){
      primes.push_back(i);
      if(is_p(i))
        p_primes.push_back(i);
    }
  }
}

int main() {
  init();
  int target;
  cin>>target;

  //upper bound는 초과하는 첫번째 원소를 찾습니다.
  //auto result = upper_bound(p_primes.begin(), p_primes.end(), target-1);
  

  //그냥 sequential search 해도 됨
  for(auto& walker : p_primes){
    if(walker >= target){
      cout<<walker;
      return 0;
    }
  }
  return 0;
}