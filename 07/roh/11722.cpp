#include<iostream>
#include<vector>
using namespace std;

vector<int> nums;
vector<int> lis;

//음수를 넣어서 LIS 알고리즘 쓰시면 됩니다.
//STACK 사용 풀이 방법을 사용해 봤습니다.

//lis에는 해당순번을 가질 수 있는 가장 작은 수를 넣습니다.
//1 3 2 4 6 7
//1
//1 3
//1 2
//1 2 4
//1 2 4 6
//1 2 4 6 7

//1. 가장 뒤에 수보다 크면 뒤에 넣는다.
//2. 해당수보다 처음으로 작은 수가 나오면 그곳에 넣는다.

//위 두과정을 반복하면 LIS 의 길이를 구할 수 있습니다.

int main(){
    int tmp2;
    cin>> tmp2;
    for(int i = 0; i<tmp2; i++){
        int tmp;
        cin >> tmp;
        nums.push_back(-tmp);
    }

    //처음에 1개는 넣어줍니다.
    lis.push_back(nums[0]);
    for(int i =1; i<tmp2; i++){

        //해당수보다 처음으로 작은수를 찾습니다.
        int idx = lower_bound(lis.begin(), lis.end(), nums[i]) - lis.begin();
        
            //똑같은 숫자가 나오면 거릅니다.
        if(nums[i] == lis[idx]){
            continue;
        }
        else{
            //마지막 숫자보다 크지 않다면
            if(idx != lis.size())
                lis[idx] = nums[i];
            //마지막 숫자보다 크다면
            else
                lis.push_back(nums[i]);
        }
    }
    cout<<lis.size();

    return 0;
}