#include <iostream>
#include <vector>
#include <algorithm>
#include <assert.h>
using namespace std;

string origin = "Messi Gimossi";

vector<long long> len;

//string(m)은 string(m-1) + ' ' + string(m-2) 으로 이루어짐
//string(m)[n] = string(m-1)[n-len(string(m-1)) - 1]

//이때 n == len(string(m-1)) 일경우
//공백 문자가 들어있는 곳이다.

char solve(int n){
    //n==len(string(m-1)) 일경우
    //n= -1값으로 solve함수에 들어오므로
    //공백을 리턴한다.    
    if(n==-1){
        return ' ';
    }
    //아니면 기본 문자열 Messi Gimossi 에서 idx찾아서 리턴
    if(n<13)
        return origin[n];
    
    //n에서 최대한 긴 문자열을 빼야하므로 이분탐색으로 찾는다.
    //미리 문자열의 길이를 vector에 저장.
    int idx = upper_bound(len.begin(), len.end(), n) - len.begin();
    //위의 점화식 그대로 코딩함.
    return solve(n - len[idx-1] - 1);

}

int main() {
    len.resize(3);
    len[0] = 0;
    len[1] = 5;//Messi
    len[2] = 13;//Messi Gimossi

    //아래코드는 버퍼 오브플로우 아슬아슬할듯.
    //solve는 받았읍니다.
    //대충 f(n) = f(n-1) + f(n-2) + 1 는... 대에충 sqrt(2)배정도씩 커질텐데 f(n) > f(n-2) + f(n-2) + 1 이니까
    //어렵넹.

    //문자열의 길이를 vector에 미리 저장합니다.
    for(int i = 3 ;i<100; i++){
        len.push_back(len[i-1] + len[i-2] + 1);
    }
    int n=0;
    cin>>n;
    //문제 그대로 코딩.
    char result = solve(n-1);
    if(result == ' ')
        cout<<"Messi Messi Gimossi";
    else
        cout<<result;
    return 0;
}