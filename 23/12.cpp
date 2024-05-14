#include <bits/stdc++.h>
#include "util.cpp"

using namespace std;

auto to_int = [](vector<string> v){
    vector<int> a;
    for (auto s: v) {
        int n = 0;
        for (auto c: s) {
            n = n*10 + (c - '0');
        }
        a.push_back(n);
    } 
    return a;
};

int main() {
    fstream f;
    f.open("12.ex.in", ios::in);
    if (f.is_open()) {
        string l;
        while (getline(f, l)) {
            int sp_i = l.find(" ");
            string springs = l.substr(0, sp_i);
            vector<int> alt = to_int(split_s(l.substr(sp_i+1), ','));
        }
    }
    return 0;
}
