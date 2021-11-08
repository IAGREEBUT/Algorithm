//
// 1753번 - 최단경로
// "다익스트라"


#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> ii;

const int INF = 1e5 * 2;//최대 정점의 수 만큼

//다익스트라
// pq는 (거리,정점)이고 graph는 (정점,거리)이다 .. 주의
vector<int> dijkstra(int vertex, int start, vector<vector<ii>> &graph) {

    priority_queue<ii, vector<ii>, greater<>> pq; //작은 순서대로 정렬 -> (start ~ vertex 거리 ,vertex )
    vector<int> dist(vertex + 1, INF);//답으로 내보낼 배열 (각 정점별 최소거리)

    //시작값 큐에 넣기
    dist[start] = 0; //start to start : 0
    pq.push({0, start});


    while (!pq.empty()) {
        int u = pq.top().second;
        int w = pq.top().first; // start -> u 까지의 weight
        pq.pop();


        if (w > dist[u]) continue; //dist[u]가 이미 w보다 작게 설정되었다는 것은 이미 검사된 정점이라는 의미 -> pass

        for (int i = 0; i < graph[u].size(); i++) { //꺼낸 정점 u와 연결된 정점들 탐색
            int node = graph[u][i].first; // u와 연결된 정점
            int weight = w + graph[u][i].second;// start -> u(w) + u -> node(graph[u][i]) = start -> node

            //새로 구한 값이 원래 저장되어 있는 값보다 작으면 갱신
            if (weight < dist[node]) {
                dist[node] = weight;
                pq.push({weight, node});
            }


        }


    }
    return dist;


}

int main() {


    int vertex, edge, k;
    cin >> vertex >> edge >> k;


    int u, v, w;

    /*
     * 인접리스트로 연결 관계 구현!
     *
     * ex) u -> (v1,w1) -> (v2,w2) : u와 v1은 w1의 가중치로 연결됨, u와 v2는 w2의 가중치로 연결됨
     * pair를 사용하는 이유 -> 정점과 가중치를 함께 저장해야 하므로 (vertex,weight) 쌍
     *
     */
    vector<vector<ii>> graph(vertex + 1, vector<ii>(0)); //vertex + 1 : 정점이 0번이 아닌 1번부터 시작해야하므로 크기가 1 크다
    while (edge--) {
        cin >> u >> v >> w;
        graph[u].emplace_back(v, w); // u -> (v,w)
    }

    //연산
    vector<int> ans = dijkstra(vertex, k, graph);

    //출력
    for (int i = 1; i <= vertex; i++) {
        if (ans[i] == INF)
            cout << "INF";
        else
            cout << ans[i];
        cout << '\n';
    }

}

