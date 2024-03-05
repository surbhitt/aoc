
#include <bits/stdc++.h>
using namespace std;

int main() {
    fstream f;
    f.open("5.ex.in", ios::in);
    string line;
    while(getline(f, line)) {
        cout << line << '\n';
    }
    return 0;
}
