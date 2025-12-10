#include <bits/stdc++.h>
#include "util.cpp"
using namespace std;

int main() {
    vector<string> input = get_input_from_file(__FILE__);
    int ans = 0;
    // part 1 make it false
    while (true) {
        int tmp = 0;
        for (int x = 0; x < input.size(); x++) {
            for (int y = 0; y < input[0].length(); y++) {
                if (input[x][y] != '@')
                    continue;
                int cnt = 0;
                for (int i = -1; i < 2; i++) {
                    for (int j = -1; j < 2; j++) {
                        if (i == 0 && j == 0)
                            continue;
                        if (x + i < input.size() && x + i >= 0 &&
                            y + j < input[0].length() && y + j >= 0 &&
                            input[x + i][y + j] == '@') {
                            cnt++;
                        }
                    }
                }
                if (cnt < 4) {
                    tmp++;
                    input[x][y] = '.';
                }
            }
        }
        if (!tmp)
            break;
        ans += tmp;
    }
    cout << ans << endl;
}
