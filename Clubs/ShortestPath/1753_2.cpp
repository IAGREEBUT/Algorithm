//
// Created by 이유정 on 2022/10/19.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 1e5 * 2;
vector<vector<int>> adj_matrix;

//다익스트라는 list로 구현해야한다.. matrix는 메모리가 너무 많이 사용됨
vector<int> dijkstra(int start, int n) {

    vector<int> answer(n + 1, INF); // start-> i번째 인덱스로의 정점 까지의 거
    vector<bool> visited(n + 1, false);
    queue<int> q;

    q.push(start);
    visited[start] = true;
    answer[start] = 0; // start->start의 거리는 0

    while (!q.empty()) {

        int v = q.front();

        q.pop();


        for (int i = 1; i <= n; i++) {


            if (!visited[i] && adj_matrix[v][i] != -1) {
                //방문한적 없고, 연결되어 있음 ( INF 이면 연결되어있지 않은거임 )
                q.push(i);
                visited[i] = true;


                if (answer[i] > answer[v] + adj_matrix[v][i]) {
                    answer[i] = answer[v] + adj_matrix[v][i];
                }
            }
        }


    }

    return answer;


}


int main() {

    int v, e, start;

    cin >> v >> e >> start;

    adj_matrix.assign(v + 1, vector<int>(v + 1, -1));

    int a, b, w;
    for (int i = 0; i < e; i++) {
        cin >> a >> b >> w;
        adj_matrix[a][b] = w; //방향 그래프임
    }


    vector<int> answer = dijkstra(start, v);

    for (int i = 1; i <= v; i++) {
        if (answer[i] == INF) cout << "INF" << "\n";
        else cout << answer[i] << "\n";
    }

}


