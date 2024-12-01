
#include "../util.cpp"
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int task1(vector<int> &l1, vector<int> &l2) {
    sort(l1.begin(), l1.end());
    sort(l2.begin(), l2.end());
    /* for (auto x: l1) cout << x << endl; */
    /* for (auto x: l2) cout << x << endl; */
    /* cout << l1[0] << " " << l2[0] << endl; */

    int ans = 0;
    for (int i = 0; i < l1.size(); i++)
        ans += abs(l1[i] - l2[i]);

    return ans;
}

int task2(vector<int> &l1, vector<int> &l2) {
    unordered_map<int, int> um;
    for (auto x : l2) {
        if (um.find(x) != um.end())
            um[x]++;
        else
            um[x] = 1;
    }
    int ans = 0;
    for (auto x : l1) {
        ans += x * um[x];
    }
    return ans;
}

int main() {
    fstream f;
    f.open("1.in", ios::in);
    string line;
    vector<vector<char>> m;
    vector<int> l1, l2;
    while (getline(f, line)) {
        vector<string> nums = split_s(line, ' ');
        l1.push_back(stoi(nums[0]));
        // unfortunately its 3 space separated so take the 4th char
        l2.push_back(stoi(nums[3]));
    }
    /* cout << task1(l1, l2); */
    cout << task2(l1, l2);

    return 0;
}
