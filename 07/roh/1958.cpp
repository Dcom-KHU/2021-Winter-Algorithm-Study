#include <iostream>
#include <string>
#include <vector>


//LCS.. 가 뭔지 몰라서 인터넷 검색후 해결했습니다.


using namespace std;

int DP[101][101][101];

string str1,str2,str3;

int max3(int a, int b, int c){
    return max(a,max(b,c));
}

//top - bottom 으로 구현했습니다.

//abc는 각 str의 idx를 의미합니다.
int LCS(int a, int b, int c){
    //prevent idx out of range
    if(a<0 || b<0 || c<0)
        return 0;
    if(a>=str1.size() || b>=str2.size() || c>=str3.size())
        return 0;

    //already calculated, just return answer
    if(DP[a][b][c] != -1)
        return DP[a][b][c];

    //점화식
    //아래식이 성립하면 common Sequence임
    if(str1[a] == str2[b] && str2[b] == str3[c]){
        //그러므로 a-1 b-1 c-1 까지의 LCS길이 + 1
        return DP[a][b][c] = LCS(a-1,b-1,c-1) + 1;
    }
    //아니면 이전idx들의 최댓값을 가져옵니다.
    return DP[a][b][c] = max3(LCS(a-1, b, c),LCS(a,b,c-1),LCS(a,b-1,c));
}

int main() {
    cin >> str1 >> str2 >> str3;
    //initializing
    for(int i= 0; i<100; i++)
        for(int j =0; j<100; j++)
            for(int k =0; k<100; k++)
                DP[i][j][k] = -1;

    cout<<LCS(str1.size()-1, str2.size()-1, str3.size()-1);

    return 0;
}