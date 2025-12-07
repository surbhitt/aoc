#include <string>
#include <fstream>
#include <vector>
using namespace std;

vector<string> get_input_from_file(string code_filename) {
    int ext_idx = code_filename.find('.');
    string input_filename =
        "input_" + code_filename.substr(0, ext_idx) + ".txt";
    fstream f;
    f.open(input_filename, ios::in);
    string line;
    vector<string> input;
    while (getline(f, line)) {
        input.push_back(line);
    }
    return input;
}

