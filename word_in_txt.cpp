//
// Created by Max on 07.02.2020.
//

#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <fstream>
#include <cctype>
#include <vector>

using namespace std;

int main() {
    ifstream input("file.txt");
    map<string, int> m;
    string s;
    while (getline(input, s, ' ')) {
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        while (s.size() != 0 && (s[s.size() - 1] < 'a' || s[s.size() - 1] > 'z')) {
            s.pop_back();
        }

        if (s.size() != 0 && 'a' <= s[0] <= 'z') {
            m[s] += 1;
        }
    }
    map<int, vector<string>> m2;

    for (auto &i : m) {
        m2[i.second].push_back(i.first);
    }
    for (auto &i : m2) {
        cout << i.first << " ";
        for (auto &i2 : i.second) {
            cout << i2 << " ";
        }
        cout << endl;
    }

}
