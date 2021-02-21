#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool comp(pair<int,int>& a, pair<int,int> & b){
    if(a.first == b.first)
        return a.second < b.second;
    return a.first < b.first;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n_lecture;
    cin>>n_lecture;
    vector<pair<int,int>> lectures;
    vector<vector<int>> classes;
    while(n_lecture--){
        int strt, fin;
        cin>>strt>>fin;
        lectures.push_back({strt, fin});
    }

    sort(lectures.begin(), lectures.end(), comp);
    
    //끝나는 시간만 priority queue에서 저장합니다.
    //새로운 강의실이 필요하면 push
    //기존의 수업이 끝나고 해당 강의실 사용가능하면
    //pop n push합니다.
    priority_queue<int, vector<int>, greater<int>> p_q;
    p_q.push(0);
    for(auto& lecture : lectures){
        if(p_q.top() <= lecture.first){
            p_q.pop();
        }
        p_q.push(lecture.second);
    }
    cout<<p_q.size();
    return 0;
}