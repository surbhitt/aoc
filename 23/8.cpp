
#include <bits/stdc++.h>
#include <cstdio>
#include <string>
#include <unordered_map>
#include <utility>
using namespace std;

unordered_map<string, pair<string, string>> um;
string inst;
int instsize;

int main() {
    fstream f;
    f.open("8.in", ios::in);
    string l;
    while(getline(f, l)) {
        int eqpos = l.find(" = ");
        if (eqpos == string::npos) {  
           inst = l;
           instsize = l.size();
           continue;
        }
        string node = l.substr(0, eqpos);
        // why in the f does nodehcild has a ) at the end????
        string nodechild = l.substr(eqpos+4, l.size()-eqpos-1);
        int compos = nodechild.find(",");
        int end = nodechild.find(")");
        string nodel = nodechild.substr(0, compos);
        string noder = nodechild.substr(compos+2, nodechild.size()-1);
        um[node] = make_pair(nodel, noder.substr(0, noder.size()-1));
    }
    int ans = 0;
    string node = "AAA";
    int i = 0; 
    while (1) {
        char cur = inst[i%instsize];
        if (cur == 'L') node = um[node].first;
        else node = um[node].second;
        i++;
        ans++;
        if (node == "ZZZ") break;
    }
    cout << "__________\n";
    cout << "ans = " << ans << endl;
    cout << "__________\n";
    return 0;
}
