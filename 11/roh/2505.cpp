#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/* 
한번만 뒤집으면 해결되는지 여부를 리턴하는 one_time함수

이후 앞에 맞춰 뒤집어보고
one_time에서 true가 리턴되는지 확인

뒤에 맞춰 뒤집어보고
one_time에서 true가 리턴된느지 화인

one_time함수는 한번 뒤집어야 하는 위치를 a,b에 저장합니다.
*/

int a, b;

bool one_time(vector<int> v){
    int i;
    for(i = 0; i<v.size(); i++){
        if(v[i] != i+1)
            break;
    }
    if(i == v.size())
        return true;
    a = i;
    for(; i<v.size()-1; i++){
        if(v[i] - v[i+1] != 1)
            break;
    }
    b = i;
    i++;
    for(; i<v.size(); i++){
        if(v[i] != i+1)
            break;
    }
    if(i == v.size())
        return true;
    return false;

}

int main() {
    int n_data;
    cin>>n_data;
    vector<int> nums;
    nums.resize(n_data);
    for(int i=0; i<n_data; i++){
        cin>>nums[i];
    }

    if(one_time(nums)){
        cout<<1<<' '<<1<<'\n';
        cout<<a+1<<' '<<b+1<<'\n';
        return 0;
    }

    int strt, fin;
    for(strt = 0; strt < n_data; strt++){
        if(strt+1 != nums[strt])
            break;
    }
    int head_idx = strt;
    for(head_idx = strt; head_idx<n_data; head_idx++){
        if(nums[head_idx] == strt+1){
            break;
        }
    }
    vector<int> temp = nums;
    if(head_idx != n_data)
        head_idx++;
    reverse(&temp[strt], &temp[head_idx]);
    if(one_time(temp)){
        cout<<strt+1<<" "<<head_idx<<'\n';
        cout<<a+1<<" "<<b+1;
        return 0;
    }
    


    for(fin = n_data-1; fin >= 0; fin--){
        if(fin+1 != nums[fin])
            break;
    }
    int tail_idx = fin;
    for(tail_idx = fin; tail_idx >= 0; tail_idx--){
        if(nums[tail_idx] == fin+1){
            break;
        }
    }
    temp = nums;
    fin++;
    reverse(&temp[tail_idx], &temp[fin]);
    if(one_time(temp)){
        cout<<tail_idx+1<<" "<<fin<<'\n';
        cout<<a+1<<" "<<b+1;
        return 0;
    }

    
    return 0;
    
}