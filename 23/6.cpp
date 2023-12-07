
#include <bits/stdc++.h>
#include <regex>
using namespace std;

int main() {
    fstream f;
    f.open("6.in", ios::in);
    string l;
    /* vector<vector<int>> a; */
    vector<vector<string>> a;
    std::regex pat{"(\\d+)"};
    while (getline(f, l)) {
        std::sregex_token_iterator it{l.begin(), l.end(), pat};
        std::sregex_token_iterator end_it;
       /* std::regex_search(l,Match,dig); */ 
        vector<string> tmp;
        while (it != end_it) {
            /* cout << "num = " <<typeof *it << endl; */
            /* tmp.push_back(stoi(*it)); */
            tmp.push_back(*it);
            ++it;
        }
        a.push_back(tmp);
        cout << endl;
    }
    int ans=0;
    long long time=0, dist=0;
    for (int i=0; i<a[0].size(); i++) {
        // part 1
        /* int tmp = 0; */
        /* for (int j=0; j<a[0][i]; ++j) { */ 
        /*     if (j*(a[0][i]-j) > a[1][i])  {tmp++;} */
        /* } */
        /* ans*=tmp; */

        // part 2
        time = time*(pow(10, (a[0][i]).size()))+stoi(a[0][i]);
        dist = dist*(pow(10, (a[1][i]).size()))+stoi(a[1][i]);
    }
    /// part 2
    for (int j=0; j<time; ++j) { 
        if (j*(time-j) > dist)  {ans++;}
    }
    cout << "\nans " << ans << endl;
    return 0;
}
