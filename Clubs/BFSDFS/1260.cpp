//
// 1260번 - DFS와 BFS
//

#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

vector<vector<int>> link;


vector<int> dfs(int n, int v) {
    vector<int> result;
    stack<int> s;
    vector<bool> visited(n + 1, false); //방문했는지 체크


    s.push(v); //첫번째 정점을 넣기
    visited[v] = true; //방문함
    result.push_back(v);//답에 방문함을 표시

    while (!s.empty()) {
        int v = s.top();
        bool check = false; // 지금 나온 정점v에 연결된 노드중 visited안된 node가 존재하나

        for (int i = 1; i <= n; i++) {
            if (link[v][i] == 1 && !visited[i]) { //i에 방문한 적 없고, v와 연결되어 있는데, (작은거부터)
                check = true;
                visited[i] = true;//방문함
                s.push(i);
                result.push_back(i); // 답에 넣기
                break; // 작은 순서대로 하기 위해 넣으면 멈추기
            }
        }

        if (!check) s.pop();

    }

    return result;


}


vector<int> bfs(int n, int v) {
    vector<int> result;
    queue<int> q;
    vector<bool> visited(n + 1, false); //방문했는지 체크


    q.push(v);
    visited[v] = true;
    result.push_back(v);

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        for (int i = 1; i <= n; i++) {

            if (link[v][i] == 1 && !visited[i]) {
                q.push(i);
                visited[i] = true;
                result.push_back(i);
            }


        }


    }


    return result;

}


int main() {

    // n: 노드의 수 , m: edge의 수 , v : 시작할 정점 번호
    int n, m, v;
    cin >> n >> m >> v;


    //edge 연결정보 저장 - 1. 이차원배열에 저장하기
    link.assign(n + 1, vector<int>(n + 1, 0));//node가 1부터시작


    int from, to;
    for (int i = 0; i < m; i++) {
        cin >> from >> to;
        link[from][to] = link[to][from] = 1; //양방향 그래프이므로
    }


//    //dfs & bfs 수행
    vector<int> dfs_res = dfs(n, v);
    vector<int> bfs_res = bfs(n, v);

//    //dfs결과 출력
    for (int i = 0; i < dfs_res.size(); i++) { //n이 아니라 dfs_res.size인 이유는 노드를 전부 방문하지 못할 수도 있기 때문( edge로 연결이 없는 경우 등) 
        cout << dfs_res[i] << " ";
    }
    cout << "\n";

//    //bfs결과 출력
    for (int i = 0; i < bfs_res.size(); i++) {
        cout << bfs_res[i] << " ";
    }


}