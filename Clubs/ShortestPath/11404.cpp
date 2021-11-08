//
// 11404번 - 플로이드
// "플로이드 - 워셜" ASP : 가능한 모든 정점 2개의 조합에 대한 최단 경로

#include <iostream>
#include <vector>

using namespace std;

const int INF = 1e7; //지나야하는 최대 간선의 수 n-1

void floydWarshall(int vertex, vector<vector<int>> &graph) {

    for (int i = 1; i <= vertex; i++) { //필수로 거쳐가야 하는 정점
        for (int j = 1; j <= vertex; j++) { // 시작 정점
            for (int k = 1; k <= vertex; k++) { // 도착 정점
                int cost = graph[j][i] + graph[i][k]; // j->i->k
                if (cost < graph[j][k])//원래 j->k로 가는 값보다 더 작으면 갱신
                    graph[j][k] = cost;
            }
        }
    }

}


int main() {

    int n, m;
    cin >> n >> m;

    //플로이드 워셜은 그래프 연결 정보를 "인접행렬"로 구현해야함
    vector<vector<int>> graph(n + 1, vector<int>(n + 1, INF)); //모든 vertex끼리의 거리니까 n+1 x n+1 (+1은 1부터 시작하려고)

    //자기자신 -> 자기자신 : 0
    for (int i = 1; i <= n; i++)
        graph[i][i] = 0;

    int u, v, w;
    while (m--) {
        cin >> u >> v >> w;
        graph[u][v] = min(graph[u][v], w); //중복 간선이 들어오면, 둘중 최소 값으로 해야함
    }

    //연산
    floydWarshall(n, graph);

    //출력
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            cout << ((graph[i][j] == INF) ? 0 : graph[i][j]) << ' ';
        cout << '\n';
    }
}