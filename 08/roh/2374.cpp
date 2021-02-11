#include <iostream>
#include <vector>
#include <assert.h>

using namespace std;

vector<long long> nums;

long long cur = 0;


//해당구간의 최댓값을 반환합니다.
//그 최댓값으로 숫자를 통일하기위해 사용해야하는 ADD함수의 개수를
//cur에 더해 넣습니다.
long long make_same(long long strt, long long end){
    
    assert(strt < nums.size());
    //구간에 숫자가 1개일때는 그냥 그숫자를 리턴
    if (strt+1 == end)
        return nums[strt];
    //구간에 숫자가 2개일때는 큰 숫자를 리턴
    //큰수 - 작은수 만큼 ADD함수 사용.
    if(strt+2 == end){
        cur += abs(nums[strt] -  nums[strt+1]);
        return max(nums[strt], nums[strt+1]);
    }
    
    //구간내 가장 큰 숫자를 찾기. segment Tree로 구성시 log n 가능.
    long long large = -1;
    long long idx = -1;
    for(long long i = strt ; i<end; i++){
        if(nums[i] > large){
            large = nums[i];
            idx = i;
        }
    }

    //가장 큰수가 구간의 가장 앞에 있지 않을때
    if(strt < idx)
        cur += large - make_same(strt, idx);
    
    //가장 큰 수가 구간의 가장 뒤에 있지 않을때
    //구간내 가장 큰 수 - sub구간내 가장 큰 수 만큰 ADD함수 사용해야함.
    if(idx+1 < end)
        cur += large - make_same(idx+1, end);

    //cout<<strt << " : "<<end<<" : "<<cur<<endl;
    return large;
}

int main() {
    long long n_data=0;
    cin>>n_data;
    //숫자 입력받으시고
    while(n_data--){
        long long temp;
        cin>>temp;
        nums.push_back(temp);
    }

    //해결!
    make_same(0,nums.size());
    cout<< cur;
    return 0;
}