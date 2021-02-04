#include <iostream>
#include <vector>

using namespace std;

int carry;    
vector<int> v;
vector<int> acc;


//dp[0][i]는 0번째 열차가 i, i-1, i-2 ... i-carry+1 번째 객차까지 끌고있음을 의미합니다.
//dp[1][i]는 1번째 열차가 i, i-1, i-2 ... i-carry+1 번째 객차까지 끌고있음을 의미합니다.
           //0번째 열차는 가장 효율좋은 k ~ k-carry+1 번재 객차를 끌고있습니다.


int dp[3][50001];

//top bottom으로 풀었습니다.
// used번쨰 열차가 cur부터 객차를 carry개 끌고있을때
// 몇명이 긴급수송 가능한지 리턴합니다.
int solve(int used, int cur){
    if(cur < carry){
        return dp[used][cur] = acc[cur];
    }
    if(dp[used][cur] != -1)
        return dp[used][cur];

    //0번째 열차 배치
    if(used == 0){
        return dp[used][cur] = max(solve(0, cur-1), acc[cur] - acc[cur-carry]);
    }
    else if(used == 1){
        //열차 2개가 cur이전의 모든 객차를 끌 수 있다면
        if(cur < carry*2){
            return dp[used][cur] = acc[cur];
        }
        //1번열차가 이전부터 끄는게 좋을지 혹은
        //cur부터 끄는게 좋은지 판단합니다.
        //acc에 객차내 승객수를 누적해서 더해두었습니다.
        //이를 이용해 구간합을 O(1)에 구할수 있습니다. 
        return dp[used][cur] = max(solve(1, cur-1), solve(0,cur-carry) + acc[cur] - acc[cur-carry]);
    }
    else{
        //열차 3개가 cur이전의 모든 객차를 끌 수 있다면
        if(cur < carry*3){
            return dp[used][cur] = acc[cur];
        }
        //2번 열차가 이전cur부터 끄는게 좋을지 혹은
        //cur부터 끄는게 좋을지 판단합니다.
        return dp[used][cur] = max(solve(2, cur-1),solve(1, cur-carry) + acc[cur] - acc[cur-carry]);
    }
}

int main() {
    ios::sync_with_stdio(false);
    //초기화
    for(int j = 0; j<3; j++)
        for(int i =0 ;i<50001; i++)
            dp[j][i] = -1;
    //입력부
    int n;
    cin>>n;

    for(int i = 0; i<n; i++){
        int temp;
        cin>>temp;
        v.push_back(temp);
    }
    cin>>carry;

    //누적합 계산
    int temp = 0;
    for(int i =0 ;i<n; i++){
        temp += v[i];
        acc.push_back(temp);
    }

    //top-bottom으로 해결합니다.
    cout<<solve(2, n-1);

    return 0;
}