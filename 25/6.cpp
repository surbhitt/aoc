#include <bits/stdc++.h>
#include "util.cpp"
using namespace std;
typedef long long ll;

ll get_ans(vector<vector<string>> calcs) {
    ll ans = 0;
    for (auto a : calcs) {
        ll tmp = 0;
        string sym = a[0];
        if (sym == "*")
            tmp = 1;
        for (int i = 1; i < a.size(); i++) {
            if (sym == "*")
                tmp *= stoi(a[i]);
            else
                tmp += stoi(a[i]);
        }
        ans += tmp;
    }
    return ans;
}

ll part_1(vector<string>& input, vector<vector<string>> calcs) {
    for (int i = 0; i < input.size() - 1; i++) {
        int j = 0;
        string cur = "";
        for (auto a : input[i]) {
            if (a != ' ') {
                cur += string{a};
            } else if (cur != "") {
                calcs[j].push_back(cur);
                j++;
                cur = "";
            }
        }
        if (cur != "")
            calcs[j].push_back(cur);
    }
    return get_ans(calcs);
}

ll part_2(vector<string>& input, vector<vector<string>> calcs) {
    int idx = 0;
    for (int j = 0; j < input[0].size(); j++) {
        string tmp = "";
        for (int i = 0; i < input.size() - 1; i++) {
            char val = input[i][j];
            if (val != ' ') {
                tmp += string{val};
            }
        }
        if (tmp != "") calcs[idx].push_back(tmp);
        else idx++;
    }
    return get_ans(calcs);
}

int main() {
    vector<string> input = get_input_from_file(__FILE__);
    string ops = input.back();
    vector<vector<string>> calcs;
    for (auto a : ops) {
        if (a != ' ')
            calcs.push_back({string{a}});
    }
    cout << part_1(input, calcs) << endl;
    //cout << part_2(input, calcs) << endl;
    return 0;
}
