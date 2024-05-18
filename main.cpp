#include<bits/stdc++.h>

using namespace std;

map<pair<int, int>, int> precount;
string s = "CGUAAUUACGGCAUUAGCAU";

int act(int v, int to) {
    if (v >= to) {
        return 1;
    }
    if (precount[make_pair(v, to)]) {
        return precount[make_pair(v, to)];
    }
    auto out = 0;
    for (int i = v + 1; i < to + 1; i += 2) {
        if (s[v] + s[i] == 'A' + 'U' || s[v] + s[i] == 'G' + 'C') {
            out += act(i + 1, to) * act(v + 1, i - 1);
        }
    }
    precount[make_pair(v, to)] = out;
    return out;
}

int main() {

    cout << act(0, 19);
}
