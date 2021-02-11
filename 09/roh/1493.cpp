#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

vector<pair<int,int>> cubes;

int cnt = 0;

int min3(int a, int b, int c){
    return min(a,min(b,c));
}

int max3(int a, int b, int c){
    return max(a,max(b,c));
}

//해당공간을 남은 큐브들로 채울수 있는지 여부를 리턴
bool solve(int len, int wid, int hei){
    if(min3(len,wid,hei) == 0)
        return true;
    for(auto& cube : cubes){
        //넣을수 있는 가장큰 큐브를 찾으면
        if(cube.first <= min3(len,wid,hei) && cube.second > 0){
            //사용한 큐브는 남아있는 큐브 배열에서 빼준다.
            cube.second -= 1;
            //큐브 사용개수를 1개늘린다.
            cnt++;
            //큐브를 넣고 남은 공간들에 대해 다음 함수 호출
            //이때 공간을 자르는 방법에 대해서 여러 방법이 있을수 잇음
            //why? 큐브의 크기가 2의 제곱승이므로 더 작은 큐브n개가
            //더큰 큐브를 대체해야만 하는 상황이 발생하지 않음.
            return solve(len-cube.first, wid, hei) 
                && solve(cube.first, wid-cube.first, hei)
                && solve(cube.first, cube.first, hei-cube.first);
        }
    }
    return false;
}

int main() {
    int length, width, height;
    cin>>length>>width>>height;
    int n_cube;
    cin>>n_cube;
    while(n_cube--){
        int s, n;
        cin>>s>>n;
        cubes.push_back({pow(2,s),n});
    }
    sort(cubes.begin(), cubes.end());
    reverse(cubes.begin(), cubes.end());
    if(solve(length, width, height))
        cout<<cnt;
    else
        cout<<"-1";
    return 0;
}