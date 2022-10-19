// 대체 왜 안되는거지..?!
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> ii;
const int INF = 1e5;

/*
 * 1. 가는시간(
 *      각자의 마을(여러개) -> 하나의 마을 (Single Destination)
 * 2. 오는시간
 *      하나의 마을(하나) -> 여러개 (Single source)
 *
 *
 */



vector<int> dijkstra(int v, int s, vector<vector<ii>> &graph) {


    priority_queue<ii, vector<ii>, greater<>> pq; // dest <- v까지의 최단가중치 , v
    vector<int> weight(v + 1, INF);


    pq.push({0, s}); //pq에는 가중치, 노드 순으로 삽입되어야 정렬이 됨
    weight[s] = 0;

    while (!pq.empty()) {

        int node = pq.top().second;
        int w = pq.top().first;

        pq.pop();

        if (w > weight[node])// 이미 갱신되었음
            continue;

        for (int i = 0; i < graph[node].size(); i++) {

            int next_node = graph[node][i].first; //node와 연결된 노드
            int next_weight = w + graph[node][i].second;// 해당 노드의 가중치

            if (weight[next_node] > w + next_weight) {
                weight[next_node] = w + next_weight;
                pq.push({w + next_weight, next_node});
            }

        }


    }


    return weight;


}


int main() {
    int n, m, x;
    vector<vector<ii>> graph(n + 1, vector<ii>(0)); // {도착노드,가중치}
    vector<vector<ii>> graph_dest(n + 1, vector<ii>(0)); // {도착노드,가중치}

    cin >> n >> m >> x;


    int a, b, c;
    while (m--) {
        cin >> a >> b >> c;
        graph[a].emplace_back(b, c); // a -- c --> b
        graph_dest[b].emplace_back(a, c);// b <-- c -- a
    }


    vector<int> source = dijkstra(n, x, graph);
    vector<int> dest = dijkstra(n, x, graph_dest);

    int answer = -1;
    for (int i = 1; i <= n; i++) {
        answer = max(answer, source[i] + dest[i]);
    }

    cout << answer;

    return 0;
}
