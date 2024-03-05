
#include <bits/stdc++.h>
#include <utility>
using namespace std;

pair<int, int> calc(char c){
    switch (c) {
        case '7': return make_pair(1,0);
        case 'F': return make_pair(0,1);
        case 'J': return make_pair(0,-1);
        case 'L': return make_pair(-1,0); 
    }
    return make_pair(0,0);
}

int main() {
    fstream f;
    f.open("10.ex.in", ios::in);
    string line;
    vector<vector<char>> m;
    while(getline(f, line)) {
        vector<char> tmp; 
        for (auto c: line) tmp.push_back(c);
        m.push_back(tmp);
        /* cout << line << '\n'; */
    }
    for (int i=0;i<m.size();i++){
        for (int j=0;j<m.size();j++){
            
        }
    }
    return 0;
}

/*
 * top : 7, F
 * down: L, J
 * left: L, F
 * right: 7, J
 */
