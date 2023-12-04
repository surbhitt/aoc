
#include <bits/stdc++.h>
using namespace std;

int main() {
    fstream file;
    file.open("1.in", ios::in);
    vector<string> digits = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    int ans = 0;
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            // first part
            int first=-1, last=-1;
            for(int i=0; line[i]!='\0'; ++i) {
                if (isdigit(line[i])){
                    if (first == -1) first = line[i]-'0';
                    last = line[i]-'0';
                }
            // second part
                for (int k=0; k<digits.size(); ++k) {
                    int tmpptr = i;
                    int j=0;
                    for (; digits[k][j]!='\0'; ++j) {
                        if (digits[k][j] == line[tmpptr]) {
                            tmpptr++;
                        } else {
                            break;
                        }
                    }
                    if (digits[k][j] == '\0') {
                        if (first == -1) first=k+1;
                        last=k+1;
                    }

                }
            }
            ans += first*10+last;
        }
    }
    cout << "\nans = " << ans << "\n";
    return 0;
}
