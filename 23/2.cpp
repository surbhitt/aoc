#include <bits/stdc++.h>
using namespace std;

int main() {
    fstream file;
    file.open("2.in", ios::in);
    int ans = 0;
    if (file.is_open()) {
        string line;
        vector<unordered_map<char, int>> minCubes;
        while (getline(file, line)) {
            int pos_col = line.find(": ");
            int i=0;
            for (;line[i]!='\0';i++){}
            string cubeSets = line.substr(pos_col+2, i);
            unordered_map<char, int> um = {{'r',0}, {'g',0}, {'b',0}};
            i=0;
            string num = "";
            while (isdigit(cubeSets[i])) {num+=cubeSets[i]; i++;}
            um[cubeSets[++i]] = stoi(num);
            for (; cubeSets[i] != '\0'; ++i) {
                if (cubeSets[i] == ',' || cubeSets[i] == ';'){
                    i+=2;
                    num = "";
                    while (isdigit(cubeSets[i])) {num+=cubeSets[i]; i++;}
                    if (um[cubeSets[i+1]] < stoi(num)) um[cubeSets[i+1]] = stoi(num);
                } 
            }
            minCubes.push_back(um);
        }
        int rm=12, gm=13, bm=14;
        for (int i=0; i<minCubes.size(); ++i) {
            // Part 1            
            /* if (minCubes[i]['r']<=rm && minCubes[i]['g']<=gm && minCubes[i]['b']<=bm ) { */
            /*     ans += i+1; */
            /*     cout << "for this " << i+1 << endl; */
            /* } */
            // Part 2
            ans+=minCubes[i]['r']*minCubes[i]['g']*minCubes[i]['b'];
        }
    }
    cout << "\nans  = " << ans << "\n";
    return 0;
}
