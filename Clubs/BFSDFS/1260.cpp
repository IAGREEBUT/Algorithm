//
// 1260번 - DFS와 BFS
//

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

vector<vector<bool>> link;//인접 행렬 (연결 여부만 알면됨 bool)
vector<vector<int>> adj_list; //인접리스트 (어떤 노드가 연결되었는지 알아야함 int(node번호) )


vector<int> dfsWithMatrix(int n, int v) {
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
            if (link[v][i] == true && !visited[i]) { //i에 방문한 적 없고, v와 연결되어 있는데, (작은거부터)
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


vector<int> bfsWithMatrix(int n, int v) {
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

            if (link[v][i] == true && !visited[i]) {
                q.push(i);
                visited[i] = true;
                result.push_back(i);
            }


        }


    }


    return result;

}


vector<int> dfsWithList(int n, int v) {
    vector<int> result;
    stack<int> s;
    vector<bool> visited(n + 1, false); //방문했는지 체크


    s.push(v); //첫번째 정점을 넣기
    visited[v] = true; //방문함
    result.push_back(v);//답에 방문함을 표시

    while (!s.empty()) {
        int v = s.top();
        bool check = false;


        for (int i = 0; i < adj_list[v].size(); i++) {

            if (!visited[adj_list[v][i]]) {
                check = true;
                visited[adj_list[v][i]] = true;
                s.push(adj_list[v][i]);
                result.push_back(adj_list[v][i]);
                break;
            }


        }

        if (!check) s.pop();

    }

    return result;


}


vector<int> bfsWithList(int n, int v) {
    vector<int> result;
    queue<int> q;
    vector<bool> visited(n + 1, false); //방문했는지 체크


    q.push(v);
    visited[v] = true;
    result.push_back(v);

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        for (int i = 0; i < adj_list[v].size(); i++) {//adj_list[v]에서 -> 0 -> 1 -> 2 ..이므로 0부터 임
            if (!visited[adj_list[v][i]]) {
                visited[adj_list[v][i]] = true;
                q.push(adj_list[v][i]);
                result.push_back(adj_list[v][i]);
            }
        }


    }


    return result;

}


int main() {

    // n: 노드의 수 , m: edge의 수 , v : 시작할 정점 번호
    int n, m, v;
    cin >> n >> m >> v;

    int from, to;

    //edge 연결정보 저장 - 1. 이차원배열에 저장하기(인접 행렬)
//    link.assign(n + 1, vector<bool>(n + 1, false));//node가 1부터시작
//
//
//
//    for (int i = 0; i < m; i++) {
//        cin >> from >> to;
//        link[from][to] = link[to][from] = true; //양방향 그래프이므로
//    }

    //edge 연결 정보 저장 - 2. 인접 리스트로 저장
    adj_list.assign(n + 1, vector<int>());//행의 수는 노드의 수 이지만, 열의 수는 유동적 (vector로 선언했을때 동적할당이 되어서 좋음)

    for (int i = 0; i < m; i++) {
        cin >> from >> to;
        //양방향 그래프임
        adj_list[from].push_back(to);
        adj_list[to].push_back(from);

    }


    //작은 순서대로 삽입하려면 각 행에 들은 값을 정렬 필요
    for (int i = 1; i <= n; i++)
        sort(adj_list[i].begin(), adj_list[i].end());



//    //dfs & bfs 수행 - 인접행렬
//    vector<int> dfs_res = dfsWithMatrix(n, v);
//    vector<int> bfs_res = bfsWithMatrix(n, v);

    // dfs & bfs 수행 - 인접 리스트
    vector<int> dfs_res = dfsWithList(n, v);
    vector<int> bfs_res = bfsWithList(n, v);



    //dfs결과 출력
    for (int i = 0; i < dfs_res.size(); i++) { //n이 아니라 dfs_res.size인 이유는 노드를 전부 방문하지 못할 수도 있기 때문( edge로 연결이 없는 경우 등)
        cout << dfs_res[i] << " ";
    }
    cout << "\n";

    //bfs결과 출력
    for (int i = 0; i < bfs_res.size(); i++) {
        cout << bfs_res[i] << " ";
    }


}