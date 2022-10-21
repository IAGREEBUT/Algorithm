//
// Created by 이유정 on 2022/10/20.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> ii;
const int INF = 1e5 * 8 * 3; // *3이유 : 방문한 정점, 간선을 중복 순회가


vector<int> dijkstra(int n, int start, vector<vector<ii>> &adj_list) {

    vector<int> dist(n + 1, INF);

    priority_queue<ii, vector<ii>, greater<>> pq;

    pq.push({0, start});
    dist[start] = 0;

    while (!pq.empty()) {

        int weight = pq.top().first;
        int node = pq.top().second;

        pq.pop();

        if (weight < dist[node]) continue;


        for (int i = 0; i < adj_list[node].size(); i++) {

            int next_node = adj_list[node][i].first;
            int next_weight = weight + adj_list[node][i].second;

            if (dist[next_node] > next_weight) {
                dist[next_node] = next_weight;
                pq.push({next_weight, next_node});
            }


        }


    }
    return dist;

}


int main() {

    int n, e;

    vector<vector<ii>> adj_list;
    adj_list.assign(n + 1, vector<ii>());

    cin >> n >> e;

    int a, b, c;

    while (e--) {

        cin >> a >> b >> c;

        adj_list[a].push_back({b, c});
        adj_list[b].push_back({a, c});

    }


    int u, v;
    vector<int> from = dijkstra(n, 1, adj_list);
    vector<int> p1 = dijkstra(n, u, adj_list);
    vector<int> p2 = dijkstra(n, v, adj_list);


    int utov = from[u] + p1[v] + p2[n]; // 1->u u->v v->n
    int vtou = from[v] + p2[u] + p2[n];

    if (utov >= INF) cout << -1;
    else
        cout << min(utov, vtou);


}