//
// 1504번 특정한 최단 경로
// ll타입에 주의하자

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;
const int INF = 1e5 * 8;

void floyd(int n, vector<vector<ll>> &dist) { //각 정점 사이의 최소거리

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                ll cost = dist[i][k] + dist[k][j];
                dist[i][j] = min(cost, dist[i][j]);
            }
        }
    }


}


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    int n, e;

    vector<vector<ll>> dist(n + 1, vector<ll>(n + 1, INF));

    cin >> n >> e;

    int a, b, v, u;
    ll c;

    for (int i = 1; i <= n; i++) //자기 자신과의 거리
        dist[i][i] = 0;

    while (e--) {
        cin >> a >> b >> c;

        //무방향임!
        dist[a][b] = min(dist[a][b], c);
        dist[b][a] = min(dist[b][a], c);

    }


    cin >> v >> u;

    floyd(n, dist);

    ll utov = dist[1][u] + dist[u][v] + dist[v][n];
    ll vtou = dist[1][v] + dist[v][u] + dist[u][n];

    if (utov >= INF) cout << -1;
    else
        cout << min(utov, vtou);

}