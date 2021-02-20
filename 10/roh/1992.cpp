#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> board;
string solve(int x_idx, int y_idx, int size){
    string result = "";
    if(size == 1)
        return result + board[y_idx][x_idx];
    string results[4];
    results[0] = solve(x_idx, y_idx, size/2);
    results[1] = solve(x_idx+size/2, y_idx, size/2);
    results[2] = solve(x_idx, y_idx+size/2, size/2);
    results[3] = solve(x_idx+size/2, y_idx+size/2, size/2);
    if(!results[0].compare(results[1]) 
        && !results[2].compare(results[3])
        && !results[1].compare(results[3])
        && results[0].size() == 1
        )
            return results[0];
    else{
        return '(' +results[0]+results[1]+results[2]+results[3] + ')';
    }
}

int main() {
    ios::sync_with_stdio(false);
    int n_size;
    cin>>n_size;
    board.resize(n_size);
    for(int i = 0; i<n_size; i++){
        cin>>board[i];
    }
    cout<<solve(0,0,n_size);
    return 0;
}