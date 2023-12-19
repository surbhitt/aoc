
#include <bits/stdc++.h>
using namespace std;

int main() {
    fstream f;
    f.open("11.in");
    string l;
    int lc=0;
    vector<pair<int, int>> pos;
    vector<int> r,c;
    int rowSize = 0;
    set<int> ec;
    while (getline(f, l)) {
        rowSize = l.size();
        bool f = true;
        for (int i=0; i<l.size(); ++i) {
            if (l[i] == '#') { 
                f = false;
                ec.insert(i);
                pos.push_back(make_pair(lc, i));
            }
        }
        if (f) r.push_back(lc);
        lc++;
        cout << l << endl;
    }

    for (int i=0; i<rowSize; i++) 
        if (ec.find(i) == ec.end()) c.push_back(i);
    cout << "r\n";
    for (auto tmp: r) cout << tmp << " ";
    cout << endl;
    cout << "c\n";
    for (auto tmp: c) cout << tmp << " ";
    long long ans=0;
    for (int i=0; i<pos.size(); ++i) {
        printf("\n\nfrom (%d, %d)\n", pos[i].first, pos[i].second);
        for (int j=i+1; j<pos.size(); ++j) {
            printf(" to (%d, %d)\n", pos[j].first, pos[j].second);
            long long cnt = 0;
            int lbr = min(pos[i].first, pos[j].first);
            int ubr = max(pos[i].first, pos[j].first); 
            int lbc = min(pos[i].second, pos[j].second);
            int ubc = max(pos[i].second, pos[j].second); 
            cout << "lbr = " << lbr << " ubr = " << ubr << endl;
            cout << "lbc = " << lbc << " ubc = " << ubc << endl;
            for (auto k: r) if (lbr < k && k < ubr) {
                cout << "entering for k in r = " << k << endl;
                // part 1
                // cnt++;
                cnt+=999999;
            }
            for (auto k: c) if (lbc < k && k < ubc) {
                cout << "entering for k in c = " << k << endl;
                // cnt++;
                cnt+=999999;
            }
            cout << "expansion has added " << cnt << endl;
            ans += abs(pos[j].first - pos[i].first) + abs(pos[j].second - pos[i].second) + cnt;
            cout << "total here was = " << pos[j].first - pos[i].first + pos[j].second - pos[i].second + cnt<< endl;
        }
    }

    cout << "\n------------\n";
    cout << ans;
    cout << endl;
    return 0;
}

