//1. 뭔가 규칙이 있을까?
//0 1 2 2 4 2 6 4 6 4 10 4 12 6 8 8 16 6 18 8 12 10
//....?
//미친....?
// f(3) = 2 -> f(9) = 6 -> f(81) : 64
//제곱수의 경우 해당 제곱수의 sqrt와 관련있는 숫자를 보임.
//f(a^2) = a * f(a)
//64?  8 : 4 64 : 32 


//f(a^2 * b) = f(b) * f(a^2) = f(b) * f(a) * a
//f(a*b*c) = a * f(b*c) = f(a)*f(b)*f(c)
// f(75) = 40? -> f(50) : 20 -> f(25) : 20 -> f(5): 4
// 둘이 뭐가다르지? 소인수 보유여부?
// f(1800) = 2 * f(900) = 2 * 30 * f(30)
//2. DP같은걸로 저장하면 조금 낫지않을까?
//10^12....를 어케 저장할까...
//대충 시간복잡도 보면 log n 혹은 sqrt(n)으로 조져야 될듯한데



#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>

using namespace std;

int DP[101] = {-1,};

vector<int> primes;

__int64_t solve(__int64_t a){
    if(a <= 100)
        return DP[a]; 
    //a가 제곱수
    __int64_t wow = sqrt(a);
    if(wow*wow == a){
        return wow * solve(wow);
    }


    //i에 prime들만 넣는방식이면 좀 더 빠름.
    //primes 배열을 10만 까지 만들면 됨.
    //a가 제곱수 * 다른수
    for(auto& prime : primes){
        if(a < prime*prime)
            break;
        if(a % (prime*prime) == 0){
            int cnt = 0;
            while( a % prime == 0){
                a /= prime;
                cnt++;    
            }
            //다른수의 소인수가 제곱수와 겹침
            if(cnt % 2 == 0)
                return pow(prime,cnt/2) * solve(pow(prime, cnt/2)) * solve(a);
            //다른수의 소인수가 제곱수와 겹치지 않음.
            else
                return pow(prime,cnt/2 + 1) * solve(pow(prime, cnt/2)) * solve(a);
        }    
    }
    
    //a는 모두 서로다른 소인수만 가짐
    __int64_t result = 1;
    for(auto & prime : primes){
        if(a%prime == 0){
            result *= (prime-1);
            a = a/prime;
        }
        if(prime > sqrt(a)){
            break;
        }
    }
    result *= a-1;
    return result;
}

int gcd(int a, int b){
    if(a% b == 0)
        return b;
    return gcd(b, a%b);
}

bool is_coprime(int a, int b){
    return (gcd(a,b) == 1);
}

void init(){
    primes.push_back(2);
    for(int i =3; i<100001; i+=2){
        double temp = sqrt(i);
        for(auto& prime : primes){
            if(prime > temp)
                break;
            if(i % prime == 0)
                continue;
        }
        primes.push_back(i);
    }
    for(int i= 1; i<=100; i++){
        int cnt = 0;
        for(int j = 1; j<=i; j++)
            if(is_coprime(i,j))
                cnt++;
        DP[i] = cnt;
    }
}

int main() {
    init();
    __int64_t target;
    cin>>target;
    cout<<solve(target);

}