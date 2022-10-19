//
// Created by 이유정 on 2022/10/19.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> ii;

const int INF = 1e5;

int sisterDijkstra(int n, int k) {

    /*
     * Single Pair : 특정 정점 사이의 최단 경로 ssp의 sub-problem
     */

    priority_queue<ii, vector<ii>, greater<>> pq;
    vector<int> dist(INF + 1, 2 * INF);

    pq.push({0, n});
    dist[n] = 0;


    while (!pq.empty()) {

        int node = pq.top().second;
        int weight = pq.top().first;

        if (node == k) {
            return dist[k];
        }

        pq.pop();

        if (weight > dist[node]) continue; //이미 확인했던 정점

        //갈 수 있는 방법 3가지 뿐 (연결된 노드 3가지라고 생각하면 될 듯)
        vector<ii> child = {{1, node + 1},
                            {1, node - 1},
                            {0, 2 * node}};
        for (int i = 0; i < 3; i++) {

            if (child[i].second >= 0 && child[i].second <= INF) { //범위 내에 존재해야함
                int next_node = child[i].second;
                int next_weight = weight + child[i].first;

                if (dist[next_node] > next_weight) {
                    dist[next_node] = next_weight;
                    pq.push({next_weight, next_node});
                }

            }

        }


    }

}


int main() {

    int n, k;

    cin >> n >> k;


    cout << sisterDijkstra(n, k);

}
