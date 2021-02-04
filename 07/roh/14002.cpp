#include <iostream>
#include <vector>

using namespace std;

//1. LIS를 구하면서 최고길이가 바뀌는순간, LIS 구성 요소가 바뀌는순가
//   마다 prev_idx에 자신의 선행 숫자의 idx를 저장합니다.


int prev_idx[1001];

int main() {
    ios::sync_with_stdio(false);
    for(int i =0 ;i<1001; i++)
        prev_idx[i] = -1;
    int n;
    cin>>n;
    vector<int> v;
    v.resize(n);
    for(int i =0 ;i<n; i++){
        cin>>v[i];
    }


    vector<pair<int,int>> stk;
    stk.push_back({-1,-1});
    for(int i = 0; i<n; i++){
        if(stk.back().first < v[i]){
            prev_idx[i] = stk.back().second;
            stk.push_back({v[i],i});
        }
        else{
            //처음으로 v[i] 보다 작은 k를 찾는 과정
            //이분탐색으로하면 좀.. 더 빨라요...
            for(int k = stk.size()-1; k>0; k--){
                if(stk[k-1].first < v[i]){
                    stk[k].first = v[i];
                    //이부분에서 바로 이전 숫자의 idx를 prev_idx에 저장합니다.
                    prev_idx[i] = stk[k-1].second;
                    stk[k].second = i;
                    break;
                }
            }
        }
    }
    
    cout<<stk.size()-1<<'\n';
    int cur = stk.back().second;
    vector<int> result;
    //가장 뒤에있는 숫자 부터 prev_idx를 계속따라가면
    //-1 까지 따라가면 LIS 를 출력가능합니다.
    while(cur != -1){
        result.push_back(v[cur]);
        cur = prev_idx[cur];
    }
    for(int i = result.size()-1; i>=0; i--)
        cout<<result[i]<<' ';
    return 0;
}
