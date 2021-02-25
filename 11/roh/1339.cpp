#include <iostream>
#include <queue>
#include <string>

//알파뱃별로 가중치를 구하고
//가중치 순서로 정렬이후 차례대로 9,8,7,6,5,4,3,2,1 과 곱한값을
//result에 더해넣는다.
//이후 출력.

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n_str;
    cin>>n_str;

    //알파뱃별 가중치 저장 배열.
    int alphabet_weight[26];
    //초기화
    for(int i=0 ;i<26; i++) alphabet_weight[i] = 0;
    
    for(int i=0; i<n_str; i++){
        string temp;
        cin>>temp;
        int weight = 1;
        //1의 자리수 부터 시작해서 하나씩 올라가며 가중치 계산.
        for(int j=temp.size()-1; j>=0; j--){
            alphabet_weight[temp[j]-'A'] += weight;
            weight *= 10;
        }
    }

    //프라이어리티 큐에 가중치 쭉 넣고
    priority_queue<int> p_q;
    for(int i =0 ; i<26; i++){
        p_q.push({alphabet_weight[i]});
    }

    int result = 0;
    //상위 9개가 9 8 7 6 5 4 3 2 1 과 곱해진다.
    for(int i =9; i>0; i--){
        result += i*p_q.top();
        p_q.pop();
    }
    cout<<result;

}