#include <bits/stdc++.h>
using namespace std;

vector<string> split_s(string s, char d) {
    // returns a vector<string> with strings seperated by delim d
    vector<string> v; 
    stringstream ss(s);
    string word;
    while (!ss.eof()) {
        getline(ss, word, d);
        v.push_back(word);
    }
    return v;
}
