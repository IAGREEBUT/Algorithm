//
// 4485번 - 녹색 옷 입은 애가 젤다지?
//

#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;
typedef tuple<int, int, int> ti;
const int INF = 1e5 * 2;
//상하좌우
int row[4] = {0, 0, 1, -1};
int col[4] = {-1, 1, 0, 0};


int dijkstra(int n, vector<vector<int>> &graph) {


    priority_queue<ti, vector<ti>, greater<>> pq;// coin, x좌표, y좌표
    vector<vector<int>> dist(n, vector<int>(n, INF));

    pq.push({graph[0][0], 0, 0});
    dist[0][0] = graph[0][0]; //가중치


    while (!pq.empty()) {

        int coin = get<0>(pq.top());
        int r = get<1>(pq.top());
        int c = get<2>(pq.top());

        pq.pop();


        if (r == n - 1 && c == n - 1) {//목표지점에 도달함
            return dist[n - 1][n - 1];
        }


        if (coin > dist[r][c]) continue; //이미 방문


        for (int i = 0; i < 4; i++) { //상하좌우 탐색

            int nr = r + row[i];
            int nc = c + col[i];


            if (nr >= 0 && nr < n && nc >= 0 && nc < n) {//일단 범위 내에 있는 경우에만


                int next_coin = coin + graph[nr][nc];
                if (dist[nr][nc] > next_coin) {
                    dist[nr][nc] = next_coin;
                    pq.push({next_coin, nr, nc});
                }

            }


        }


    }

    return dist[n - 1][n - 1]; //최종 도착지에서의 최소

}


int main() {

    int n, coin;//동굴의 크기
    vector<vector<int>> cave;

    int number = 1;
    while (true) {

        cin >> n;

        if (n == 0)break;

        cave.assign(n, vector<int>(n, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> coin;
                cave[i][j] = coin;
            }
        }


        cout << "Problem " << number++ << ": " << dijkstra(n, cave) << "\n";


    }


}

