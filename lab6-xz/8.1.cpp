#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> G(100000);
vector<int> dist(100000, 1000000000);
queue<int> q;

void bfs(int v) {
    for (int i: G[v]) {
        if (dist[i] == 1000000000) {
            dist[i] = dist[v] + 1;
            q.push(i);
        }
    }
    if (!q.empty()) {
        int x = q.front();
        q.pop();
        bfs(x);
    }
}


int main() {

    int n, m, k;
    cin >> n;
    cin >> m >> k;

    for (int i = 0; i < m; ++i) {
        int start, end;
        cin >> start >> end;
        G[start].push_back(end);
        G[end].push_back(start);
    }
    dist[1] = 0;
    bfs(1);
    bool check = false;
    for (int i = 0; i < n + 1; ++i) {
        if (dist[i] == k) {
            cout << i << '\n';
            check = true;
        }
    }

    if (!check) {
        cout << "NO";
    }



    return 0;

}
