#include <iostream>
#include <vector>
#include <queue>

using namespace std;


//앞으로 사용안할 머신의 플러그를 뽑거나
//가장 나중에 사용할 머신의 플러그를 뽑으면 됩니다.
//구멍과 머신의 개수가 100개이므로 n^3은 가능.
    

//지금 머신이 플러그에 꽂혀있는지 확인
bool is_in(const vector<int>& v, int target){
    for(auto& walker : v)
        if(walker == target)
            return true;
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //입력을 받아줍니다.
    int n_hole, n_machine;
    cin>>n_hole>>n_machine;

    //벡터 컨테이너에 저장.
    vector<int> m_nums;
    for(int i = 0; i<n_machine; i++){
        int temp;
        cin>>temp;
        m_nums.push_back(temp);
    }


    //멀티탭의 i번째 포트에는 n번째 머신이 꽂혀 있습니다.
    vector<int> multitab;
    int n_plug_out = 0;
    for(int machine_num = 0; machine_num<m_nums.size(); machine_num++){
        auto& machine = m_nums[machine_num];
        //머신이 이미 사용중이라면
        if(is_in(multitab, machine))
            continue;
        //새로운 포트가 비어있다면
        if(multitab.size() < n_hole)
            multitab.push_back(machine);
        //그 이외의 경우에는 가장 나중에 사용할 머신을 뽑습니다.
        else{
            //multitab의 i번째에 꼳혀 있는 머신이 이다음에 언제 사용되는지 저장.
            int next_idxs[101];

            //굉장히 큰수로 초기화를 해주고
            for(int i = 0; i<101; i++) next_idxs[i] = 987654321;
            
            for(int i = 0; i<multitab.size(); i++){
                //멀티탭의 i번째 머신의 다음 사용 요청이 언제들어오는지
                for(int j = machine_num; j<n_machine; j++){
                    if(multitab[i] == m_nums[j]){
                        next_idxs[i] = j;
                        //사용 요청을 찾으면 break
                        break;
                    }
                }
            }
            int best_idx = 0;

            //가장 나중에 사용요청이 들어오는 머신의 멀티탭 번호를 찾는다.
            for(int i = 0; i<multitab.size(); i++){
                if(next_idxs[best_idx] < next_idxs[i]){
                    best_idx = i;
                }
            }

            //찾은 멀티탭 번호의 슬롯에 머신을 바꿔 낀다
            multitab[best_idx] = machine;
            n_plug_out++;
        }
    }
    cout<<n_plug_out;
    return 0;
}