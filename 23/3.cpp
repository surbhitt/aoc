
#include <bits/stdc++.h>
using namespace std;

int main() {
    int ans=0;
    fstream file;
    file.open("3.in", ios::in);
    if (file.is_open()) {
        string line;
        vector<vector<int>> map;
        unordered_map<int, int> um;
        int key = 1;
        while (getline(file, line)) {
            vector<int> tmp;
            for (int i=0; line[i] != '\0'; ++i) {
                if (isdigit(line[i])) { 
                    int num = line[i]-'0';
                    tmp.push_back(key);
                    i++;
                    while (isdigit(line[i])) {
                        tmp.push_back(key);
                        num*=10;
                        num+= line[i]-'0';
                        i++;
                    }
                    um[key] = num;
                    key++;
                    i--;
                }
                // part 1
                /* else if (line[i] == '.') {
                    tmp.push_back(0);
                } else {
                    tmp.push_back(-1);
                } */
                // part 2
                else if (line[i] == '*') {
                    tmp.push_back(-1);
                } else {
                    tmp.push_back(0);
                } 
            }
            map.push_back(tmp);
        }
        set<int> vis;
        int row_size = map[0].size();
        int col_size = map.size();
        for (int i=0; i<col_size; i++) {
            for (int j=0; j<row_size; j++) {
                /* printf("i=%d, j=%d, map[i][j]=%d\n", i, j, map[i][j]); */
                if (map[i][j] == -1) {
                    int cnt = 0;
                    int ratio = 1;
                    for (int p = -1; p<2; ++p) {
                        for (int q = -1; q<2; ++q) {
                            int ni = i+p, nj = j+q;
                            if ( 0<=ni<=col_size && 0<=nj<=row_size && map[ni][nj] > 0&& vis.find(map[ni][nj]) == vis.end()) {
                                // part 1
                                // ans += um[map[ni][nj]];
                                // part 2
                                ratio*=um[map[ni][nj]];
                                cnt++;
                                vis.insert(map[ni][nj]);       
                            }
                        }
                    }
                    if (cnt == 2) ans+= ratio;
                }
            }
        }
    }
    cout << "\nans = " << ans << "\n";
    return 0;
}
