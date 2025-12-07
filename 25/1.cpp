#include <iostream>
#include <string>
#include <vector>
#include "util.cpp"
using namespace std;

int cur = 50, mod = 100;
void part_1(string inst, int* cnt) {
    char dir = inst[0];
    int clicks = stoi(inst.substr(1));
    clicks %= mod;
    if (dir == 'L') {
        cur = (cur - clicks + mod) % mod;
    } else {
        cur = (cur + clicks) % mod;
    }
    if (cur == 0)
        (*cnt)++;
}

void part_2(string inst, int* cnt) {
    char dir = inst[0];
    int clicks = stoi(inst.substr(1));
    (*cnt) += clicks / mod;
    clicks %= mod;
    if (dir == 'L') {
        if (cur < clicks && cur != 0) (*cnt)++;
        cur = (cur - clicks + mod) % mod;
    } else {
        if (cur + clicks > mod) (*cnt)++;
        cur = (cur + clicks) % mod;
    }
    if (cur == 0)
        (*cnt)++;
}

int main() {
    vector<string> input = get_input_from_file(__FILE__);
    int ans1 = 0, ans2 = 0;
    for (auto inst : input) {
        // part_1(inst, &ans1);
        // reset cur to 50
        part_2(inst, &ans2);
    }
    cout << ans2 << endl;
}
