#include <bits/stdc++.h>

using namespace ::std;

vector<int> ans;

/* Тест для графа из №3
 * 21 42
1 2 2
1 3 4
1 4 1
2 3 3
2 5 1
3 5 2
3 6 2
4 6 5
4 7 4
5 8 3
6 8 3
6 9 2
6 10 4
6 7 3
7 11 2
8 15 8
8 12 1
9 12 3
9 13 2
9 10 3
10 13 6
10 14 3
10 11 6
11 14 4
11 18 2
12 15 6
12 13 3
13 15 4
13 16 2
13 14 5
14 17 2
14 18 1
15 19 6
15 16 2
16 19 2
16 20 1
16 17 1
17 20 3
17 18 8
18 20 5
19 21 2
20 21 8


 */




void get_path(int v, int to, vector<vector<int>> &p){
    ans.push_back(to + 1);

    if(p[v][to] != v){
        get_path(v, p[v][to], p);
    }
}
int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n, vector<int> (n, 1e8));
    vector<vector<int>> p(n, vector<int> (n, -1));
    for(int i = 0; i < n; ++i){
        g[i][i] = 0;
        p[i][i] = i;
    }
    for(int i = 0; i < m; ++i){
        int x, y, l;
        cin >> x >> y >> l;
        --x;
        --y;
        g[x][y] = min(g[x][y], l);
        p[x][y] = x;
        p[y][x] = y;
        g[y][x] = min(g[y][x], l);
    }
    for(int k = 0; k < n; ++k){
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                if(g[i][j] > g[i][k] + g[k][j]){
                    g[i][j] = g[i][k] + g[k][j];
                    p[i][j] = k;
                }
            }
        }
    }
    cout << "Distance matrix:\n";
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            cout << setw(3) << g[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl << endl;
    cout << "Shortest path matrix:\n";
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            get_path(i, j, p);
            if(i != j) {
                ans.push_back(i + 1);
            }
            reverse(ans.begin(), ans.end());
            cout << "{";
            for(int l = 0; l < ans.size(); ++l){
                cout << ans[l];
                if(l != ans.size() - 1){
                    cout << " ";
                }

            }
            cout << "}, ";
            ans.clear();
        }
        cout << endl;
        cout << endl;
    }
    //acfimpsz

}
