#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
// x 좌표 기준으로 정렬
// y 좌표 기준으로 정렬
// priority queue에 인접한 두 점을 잇는 간선길이로 오름차순 정렬 되게 넣는다.
// query를 health순으로 정렬 
// union find로 처리.
// 각각의 health미만의 길이를 가진 간선들은 priority queue에서 빼고(사용가능한 간선이 됬으므로)
// 해당 간선들을 union of set로 생각해서 disjoint set으로 묶어주고 union find를 strt, dest에 대해 진행한다.
// 해당 결과값은 query_result에 저장.

// disjoint set 위한 parent 배열
int parent[250002];

// query들의 수행 결과를 yes or no 로 저장
string query_result[250002];

// 처음 입력받은 점들을 저장할곳.
// points[idx] <- idx+1번째 점을 의미함.
// why? 문제는 1번째 점부터 시작하기 때문이다.
vector<pair<int,int>> points;

// 비교용 comperator {idx, {x, y}} 형태로 구성된 데이터의 x를 비교하는데 사용
bool comp_x(pair<int, pair<int,int>>& a, pair<int, pair<int,int>>& b){
    if(a.second.first == b.second.first)
        return a.second.second < b.second.second;
    return a.second.first < b.second.first;
}


// 비교용 comperator {idx, {x, y}} 형태로 구성된 데이터의 y를 비교하는데 사용
bool comp_y(pair<int,pair<int,int>>& a, pair<int,pair<int,int>>& b){
    if(a.second.second == b.second.second)
        return a.second.first < b.second.first;
    return a.second.second < b.second.second;
}

//disjoint set
int get_p(int child){
    if(parent[child] == -1)
        return child;
    return parent[child] = get_p(parent[child]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    //초기화
    for(int i =0 ;i<250002; i++) query_result[i] = parent[i] = -1;

    int n_point, n_query;
    cin>>n_point>>n_query;


    // {idx , {x, y}}
    vector<pair<int,pair<int,int>>> idx_points;
    idx_points.reserve(n_point);
    //점들의 x,y좌표를 입력받는다.
    for(int i = 0; i<n_point; i++){
        int x, y;
        cin>>x>>y;
        points.push_back({x,y});
        idx_points.push_back({i,{x,y}});
    }

    // {dist, {strt_idx, end_idx}}
    priority_queue<pair<int, pair<int,int>>> dists;

    // x기준 정렬
    sort(idx_points.begin(), idx_points.end(), comp_x);
    
    // x기준 정렬후 인접한 점끼리의 거리를 priority queue에 넣습니다.
    for(int i = 1; i<idx_points.size(); i++){
        int dist = idx_points[i].second.first - idx_points[i-1].second.first;
        int idx1 = idx_points[i].first;
        int idx2 = idx_points[i-1].first;
        dists.push({-dist, {idx1, idx2}});
    }
    
    // y기준 정렬
    sort(idx_points.begin(), idx_points.end(), comp_y);
    
    // x기준 정렬후 인접한 점끼리의 거리를 priority queue에 넣습니다.
    for(int i = 1; i<idx_points.size(); i++){
        int dist = idx_points[i].second.second - idx_points[i-1].second.second;
        int idx1 = idx_points[i].first;
        int idx2 = idx_points[i-1].first;
        dists.push({-dist, {idx1, idx2}});
    }


    // health, {query_num , {strt, dest}}
    // 쿼리를 저장합니다.
    priority_queue<pair<int, pair<int, pair<int,int>>>> querys;
    for(int i = 0; i<n_query; i++){
        int strt, dest, health;
        cin>>strt>>dest>>health;
        //오름차순 정렬을 하고싶은데 prioriy_queue내부에 comp함수를 넣어주기 귀찮아서
        //그냥 health를 음수로 쓰고 내림차순 정렬했습니다.
        querys.push({-health, {i, {strt-1, dest-1}}});
    }

    // 쿼리를 하나씩 수행해서 결과를 저장합니다.
    while(!querys.empty()){
        auto query = querys.top();
        int health = query.first;
        int q_num = query.second.first; // 쿼리번호
        int strt = query.second.second.first; // 시작점
        int dest = query.second.second.second; // 도착점

        
        // health 기준으로 이동가능한 간선들은 모두 set로 만들어 줍니다.
        // 음수로 저장하고 내림차순 했으므로 음수부호를 붙여서 대소비교를 진행합니다.
        while(!dists.empty() && -(dists.top().first) <= -health){
            auto point = dists.top().second;
            int x= point.first;
            int y = point.second;
            int p_x = get_p(x);
            int p_y = get_p(y);

            //disjoint set의 union진행
            if(p_x == p_y){
                ;
            }
            else if (p_x < p_y){
                parent[p_y] = p_x;
            }
            else {
                parent[p_x] = p_y;
            }
            dists.pop();
        }
        //쿼리에 대한 결과값 저장.
        if(get_p(strt) == get_p(dest)){
            query_result[q_num] = "YES"; 
        }
        else
            query_result[q_num] = "NO";
        querys.pop();
    }
    //쭉 출력해 줍니다.
    for(int i = 0; i<n_query; i++){
        cout<<query_result[i]<<'\n';
    }

    // 시간 복잡도
    // n : point의 개수 q: query의 개수
    // point x,y기준 정렬 + query health기준 정렬
    // n log n + q log q 

    return 0;
}