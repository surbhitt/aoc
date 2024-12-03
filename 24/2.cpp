#include "../util.cpp"
#include <bits/stdc++.h>
using namespace std;
bool valid_dif(int n1, int n2) { return abs(n1 - n2) < 4 and abs(n1 - n2) > 0; }

int task1(vector<string> &nums) {
    int n1 = stoi(nums[0]), n2 = stoi(nums[1]);
    int dir = n1 > n2 ? 0 : 1;
    if (!valid_dif(n1, n2))
        return 0;

    bool safe = true;
    for (int i = 1; i < nums.size(); i++) {
        n2 = stoi(nums[i]);
        n1 = stoi(nums[i - 1]);
        if (dir) {
            if (n1 > n2 or !valid_dif(n1, n2)) {
                safe = false;
                break;
            }
        } else {
            if (n1 < n2 or !valid_dif(n1, n2)) {
                safe = false;
                break;
            }
        }
    }
    if (safe)
        return 1;
    return 0;
}

int task2(vector<string> nums) {
    for (int i = 0; i < nums.size(); i++) {
        vector<string> nums_c = nums;
        nums_c.erase(nums_c.begin() + i);
        if (task1(nums_c))
            return 1;
    }
    return 0;
}
int main() {
    fstream f;
    f.open("2.in", ios::in);
    string line;
    int cnt = 0;
    while (getline(f, line)) {
        vector<string> nums = split_s(line, ' ');
        // TASK 1
        /* cnt += task1(nums); */
        cnt += task2(nums);
        /* cout << "cnt=" << cnt << endl << endl; */
    }
    cout << cnt;
}
