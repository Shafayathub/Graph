#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, e;
    cin >> n >> e;

    vector<pair<int, int>> edge_list;

    while(e--){
        int a,b;
        cin >> a >> b;
        edge_list.push_back({a,b});
    }
    for(auto x : edge_list){
        cout << x.first << " " << x.second << endl;
    }

    
    return 0;
}