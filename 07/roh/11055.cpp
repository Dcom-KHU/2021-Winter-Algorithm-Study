#include <iostream>
#include <vector>

using namespace std;

vector<int> nums;


//0~i번째 숫자로 만들수 있는 부분수열중
//i 번째 index에 있는 숫자를 꼭 사용했을때 만들수있는
//총합이 가장 큰 증가 부분 수열의 총합을
//DP[i] 번째에 저장합니다.
int DP[1001];


//f(idx) = f(k) + num[idx]
//이때 k는 (num[k]<num[idx] && k<idx) 면서 f(k)값을 최대로 함.

int solve(int idx){
    int large = 0;
    for(int i = idx-1; i>=0; i--){
        if(nums[i] < nums[idx]){
            large = max(large, DP[i]);
        }
    }
    return DP[idx] = large + nums[idx];
}

int main() {
    //초기화
    for(int i =0 ;i<1001; i++)
        DP[i] = -1;
    
    //입력부분
    int n;
    cin>>n;
    while(n--){
        int temp;
        cin>>temp;
        nums.push_back(temp);
    }

    //초깃값 설정
    DP[0] = nums[0];
    int large = nums[0];
    
    //bottom - top으로 구현했습니다.
    for(int i = 1; i<nums.size(); i++){
        large = max(solve(i), large);
    }

    cout<<large;
    return 0;
}