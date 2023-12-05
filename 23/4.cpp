#include <bits/stdc++.h>
#include <cctype>
using namespace std;

int main() {
    fstream f;
    f.open("4.in", ios::in);
    string line;
    int ans = 0, ln=1;
    unordered_map<int, int> m;
    while(getline(f,line)) {
        int col_pos = line.find(": ");
        string nums = line.substr(col_pos+2, line.length()); 
        int bar_pos = nums.find(" | ");
        string win = nums.substr(0, bar_pos);
        string own = nums.substr(bar_pos+3, nums.size());
        set<string> win_set;
        string num="";
        for (int i=0; i<win.size(); ++i) {
            if (!isdigit(win[i])) {
                if (num != "") {
                    win_set.insert(num);
                    num=""; 
                }
            } else num+=win[i];
        }
        if (num != "") win_set.insert(num);
        int cnt = 0;
        num = "";
        for (int i=0; i<own.size(); ++i) {
            if (own[i] == ' ') {
                if (num != "" && win_set.find(num) != win_set.end())  {
                    cnt++;
                }
                num = "";
            } else {
                num+=own[i];
            }
        }
        if (num != "" && win_set.find(num) != win_set.end())  {
            cnt++;
        }

        // part 1
        /* if (cnt == 1) ans += 1; */
        /* else if (cnt > 1) ans += 1 << (cnt-1); */
        // part 2
        int tmp = 0;
        // getting the copies
        if (m.find(ln) != m.end()) tmp = m[ln];
        // original one
        tmp++;
        ans+=tmp;
        for(int i=1; i<=cnt; ++i) {
            if (m.find(ln+i) != m.end()) m[ln+i] += tmp;
            else m[ln+i] = tmp;
        }
        ln++;
    }
    cout << "\nans = " << ans << "\n";
    return 0;
}
