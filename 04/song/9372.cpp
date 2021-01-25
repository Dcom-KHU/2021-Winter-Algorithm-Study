#include <iostream>
using namespace std;

int main()
{
    int t,n,m; //t:테스트 케이스의 수, n:국가의 수, m:비행기의 종류
    cin>>t;
    for(int i=0;i<t;i++)
    {
        cin>>n>>m;
        for(int j=0;j<m;j++)
        {
            int tmp1, tmp2;
            cin>>tmp1>>tmp2; //간선정보 사용X
        }
        //연결 그래프이므로 모든 정점 간 경로가 존재 -> 간선의 최소 개수는 (정점의 개수-1) 
        cout<<n-1<<endl; 
    }
    return 0;
}