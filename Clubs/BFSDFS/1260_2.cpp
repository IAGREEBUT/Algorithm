//
// Created by 이유정 on 2022/10/14.
//

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>


using namespace std;


vector<vector<int>> adj_list;


//stack
vector<int> dfs(int n, int start) {

    vector<bool> checked(n + 1, false);
    vector<int> answer;
    stack<int> s;

    s.push(start);
    checked[start] = true;
    answer.push_back(start);

    while (!s.empty()) {

        int v = s.top();
        bool check = false; //v의 자식이 아직도 남아있는지 체크 용도

        for (int i = 0; i < adj_list[v].size(); i++) {

            int u = adj_list[v][i];

            if (!checked[u]) { // 사용된 적이 없어야됨
                checked[u] = true;
                check = true; //자식을 발견했으므로 true로 변경
                answer.push_back(u);//자식을 찾는 순간 탐색에 넣음
                s.push(u);
                break; //다른 자식은 넣지않음(작은것 부터 최대한 깊게 탐색하기 위해)
            }

        }

        if (!check) {//전부 탐색했는데도 더이상 자식이 없음-> pop가능  (미리 팝해주면 스택이 비게됨)
            s.pop();
        }


    }

    return answer;

}


//queue
vector<int> bfs(int n, int start) {

    //사용 여부를 확인
    vector<bool> checked(n + 1, false);
    //큐
    queue<int> q;
    //방문 순서를 저장할 정답 배열
    vector<int> answer;

    q.push(start);
    checked[start] = true; //사용 여부

    while (!q.empty()) { //q에 무언가가 계속 있는동안 반복

        // 정점 v -> u
        int v = q.front();
        q.pop();
        answer.push_back(v);//정답에 넣어주기

        //adj_list를 사용하는 방법
        for (int i = 0; i < adj_list[v].size(); i++) {

            int u = adj_list[v][i]; //v와 연결된 정점 u
            if (!checked[u]) { // 사용된 적이 없어야됨
                // 연결되어있고 + 사용된적 없으면 큐에 삽입해야하는데 정점번호가 작은것 부터 방문해야하기 때문에 어디에 저장했다가 정렬해서 넣어주기
                checked[u] = true;
                q.push(u);
            }
        }


    }

    return answer;


}


int main() {

    int v, e, start;

    cin >> v >> e >> start;


    //edge의 연결관계
    //1. adj matrix

//    adj_matrix.assign(v + 1, vector<int>(v + 1, false)); // 정점들의 연결관계를 저장한 matrix
//
//    int a, b;
//    for (int i = 0; i < e; i++) {
//        cin >> a >> b;
//
//        //방향 그래프 이므로 둘다 연결시켜줘야함
//        adj_matrix[a][b] = true;
//        adj_matrix[b][a] = true;
//
//    }


    adj_list.assign(v + 1, vector<int>());

    int a, b;
    for (int i = 0; i < e; i++) {

        cin >> a >> b;

        //양방향 그래프임
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);

    }

    //list 각각에 들어있는 정점들이 정렬되어야 순차적으로 삽입됨
    for (int i = 0; i <= v; i++) {
        sort(adj_list[i].begin(), adj_list[i].end());
    }


    vector<int> dfs_ans = dfs(v, start);
    for (int i = 0; i < dfs_ans.size(); i++) {
        cout << dfs_ans[i] << " ";
    }
    cout << "\n";


    vector<int> bfs_ans = bfs(v, start);
    for (int i = 0; i < bfs_ans.size(); i++) {
        cout << bfs_ans[i] << " ";
    }


}