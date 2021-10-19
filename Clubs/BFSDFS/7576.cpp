//
// 7565번 - 토마토
// BFS탐색

#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> ii;

//토마토의 상태를 입력받을 배열
vector<vector<int>> tomato;

//BFS 사용을 위한 Queue
queue<ii> q;


//BFS로 문제를 해결
int detectTomato(int cnt) {
    //상하좌우(이동을 위해) -> 익은 토마토 기준 상하좌우를 익게 만들어야함
    int row[4] = {-1, 1, 0, 0};
    int col[4] = {0, 0, -1, 1};

    int t = 0; //시간
    while (!q.empty()) {
        int nr = q.front().first; //y좌표(row)
        int nc = q.front().second;//x좌표(col)
        q.pop();
        t = tomato[nr][nc]; //해당 위치의 토마토가 익는데 걸린 시간 -> 익은 토마토가 동시에 주변을 익히기 시작하므로, 익은 토마토가 여러개일 수 있으니까 이런식으로 해야함(순차대로 해서 t++로 저장하면, 한번에 익는게 성립이 어려움)
        cnt--;//익지 않은 토마토 수 감소

        //상하좌우 탐색
        for (int i = 0; i < 4; i++) {//상하좌우 4가지
            int r = nr + row[i]; //이동한 행
            int c = nc + col[i]; //이동한 열

            if (tomato[r][c] == 0) { // 해당 부분이 0이면(안익은 토마토)
                tomato[r][c] = t + 1;// 시간 + 1을 저장 (배열안에 해당 토마토가 익는데 걸리는 시간을 저장함 )
                q.push(ii(r, c));//q에 넣어서 bfs탐색
            }

        }

    }

    if (!cnt) //토마토가 다 익었다면
        return t - 1; //처음에 이미 익어있는게 1초부터 시작해서 -1해줘야함
    return -1;//탐색이 끝났는데 다 안익었으면, 익을 수 없는 배치였음
}


int main() {

    int m, n;
    cin >> m >> n;

    tomato.assign(n + 2, vector<int>(m + 2, -1));// 테두리를 만들고 안되는 지역(-1)으로 만들어버리기

    //토마토 입력받기
    int num;
    int cnt = m * n;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> num;
            tomato[i][j] = num;
            if (num == 1) q.push(ii(i, j));//1이면 큐에 삽입 (이미 익은 토마토 부터 탐색이 시작됨)
            else if (num == -1) cnt--; //-1이면, 토마토없음
        }
    }

//
//    for (int i = 0; i < n + 2; i++) {
//        for (int j = 0; j < m + 2; j++) {
//            cout << tomato[i][j] << " ";
//        }
//        cout << "\n";
//    }

    cout << detectTomato(cnt);
    return 0;


}