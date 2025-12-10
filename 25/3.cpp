#include <iostream>
#include "util.cpp"
using namespace std;

typedef long long ll;

int part_1(string bank) {
    int first = bank[bank.length() - 2] - '0', second = bank.back() - '0';
    cout << first << " " << second << endl;
    cout << bank << endl;
    for (int i = bank.length() - 3; i >= 0; i--) {
        int val = bank[i] - '0';
        if (val >= first) {
            if (first > second)
                second = first;
            first = val;
        }
        cout << first << " " << second << endl;
    }
    return first * 10 + second;
}

ll part_2(string bank) {
    vector<char> val(bank.begin() + bank.length() - 12, bank.end());

    for (int i=bank.length() - 13; i>=0 ; i--) {
        int idx = 0, cur = bank[i];
        while (cur - '0' >= val[idx] - '0') {
            int tmp = val[idx];
            val[idx] = cur; 
            cur = tmp;
            idx++;
        }
    }

    ll val_i = 0;
    for (auto a : val) {
        val_i = val_i * 10 + (a - '0');
    }
    return val_i;
}

int main() {
    vector<string> input = get_input_from_file(__FILE__);
    ll ans = 0;
    for (auto bank : input) {
        // ans += part_1(bank);
        ans += part_2(bank);
    }
    cout << ans << endl;
}

