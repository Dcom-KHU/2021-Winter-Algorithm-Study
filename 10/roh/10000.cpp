#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

bool comp(pair<int,int>& a, pair<int,int> & b){
    if(a.first == b.first)
        return a.second  > b.second;
    return a.first < b.first;
}

void print(vector<pair<int,int>> & v){
    for(auto& walker : v){
        cout<<"<"<<walker.first <<", "<<walker.second<<">"<< ' ';
    }
    cout<<endl;
}

void print(vector<int>& v){
    for(auto& walker : v){
        cout<<walker<<' ';
    }
    cout<<endl;

}


int main() {
    ios::sync_with_stdio(false);
    int n_circle;
    cin>>n_circle;
    set<int> left, right;
    int cnt = 1;
    vector<pair<int,int>> circles;
    while(n_circle--){
        int center, rad;
        cin>>center>>rad;
        circles.push_back({center-rad,center + rad});
    }
    sort(circles.begin(), circles.end(), comp);
    
    bool flag = true;
    vector<pair<int,int>> checker;
    vector<int> depths;
    int max_right = 0;

    for(auto& circle : circles){
        cnt++;
        if(max_right <= circle.first){
            checker.clear();
            depths.clear();
        }
        max_right = max(circle.second, max_right);
        if(checker.empty() || checker.back().first == circle.first){
            checker.push_back(circle);
            depths.push_back(circle.second - circle.first);
            continue;
        }

        //그 앞에서 끝나는 친구들은 다 빼버린다.
        int cur_right = checker.back().second;
        int cur_depth = depths.back();
        while(checker.back().second <= circle.first){
            cur_right = checker.back().second;
            cur_depth = depths.back();
            checker.pop_back();
            depths.pop_back();
        }
        
        if(cur_right == circle.first){
            depths.push_back(circle.second - circle.first + cur_depth);
            if(depths.back() == checker.back().second - checker.back().first)
                cnt++;
            checker.push_back(circle);
            continue;
        }
        checker.push_back(circle);
        depths.push_back(circle.second - circle.first);
    
    }
    cout<<cnt;
    return 0;
}