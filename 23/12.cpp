
#include <bits/stdc++.h>
using namespace std;

int main() {
    fstream f;
    f.open("12.ex.in", ios::in);
    string l;
    while (getline(f, l)) {
        cout << l;
    }
    return 0;
}
