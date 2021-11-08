//
// 11657번 - 타임머신
// 벨만-포드 : SSP, 가중치에 음수가 존재해서 다익스트라를 사용했을 때 무한 loop에 빠질 수 있을 때 사용

/*
 * 음의 사이클 ?
 * 가중치가 음인 부분이 존재하는 경우, 계속해서 가중치가 음으로 갱신되며, 사이클에 빠질 수 있음
 * -> 이를 해결하기위해 사이클이 생겼는지 여부를 판단함
 * how? 정점의 수가 v개 일 때, a->b경로에는 최대 v-1개의 간선이 존재 가능(모든 정점을 통과해서 도달한 경우)
 * 즉, a->b의 최단 경로를 이루는 간선이 v개 이상인 정점 a,b가 존재한다 : 사이클이 생겼다
 *
 */

#include <iostream>
#include <vector>
#include <tuple>

using namespace std;
typedef long long ll;
typedef tuple<int, int, int> ti;
const int INF = 1e6 * 5;

//벨만-포드
vector<ll> bellmanFord(int n, int m, int start, vector<ti> &edges) {
    //오버플로우 X, 언더플로우 O
    //500(v의 수 최대값) * 6,000(e의 수 최대값) * (-10,000:노선최소) => int 범위 넘어감!
    vector<ll> dist(n + 1, INF); // 해당 정점까지의 최단 거리를 저장한 배열

    dist[start] = 0; //시작 위치 초기화

    for (int i = 1; i <= n; i++) { // m개의 간선을 전부 검사 했을 때 i++ 됨 : 즉 이번이 몇번째 검사인지 count가능
        bool flag = true; //더 이상 반복문을 실행할 필요가 없는지 확인 (갱신 여부 : false: 갱신됨 / true : 갱신안됨 -> 더 탐색할 필요 없이 종료가능 )
        for (int j = 0; j < m; j++) { //저장된 m개의 간선을 하나씩
            //s->d로 가는 간선의 가중치가 w
            int s = get<0>(edges[j]); // from
            int d = get<1>(edges[j]); // to
            int w = get<2>(edges[j]); // weight

            if (dist[s] == INF) //아직 시작점에서 s로 가는 경로가 발견되지 않았으므로 갱신할 수 없음
                continue;

            // 시작지점(start)에서 s정점으로 가는 경로를 알고 있는 경우
            ll next_weight = w + dist[s]; // 현재 edge( s->d) 의 가중치 + (start->s) : start -> d 로의 가중치
            if (dist[d] > next_weight) { //현재까지 저장된 가중치 보다 새로 계산한 가중치가 적은 경우 갱신
                if (i == n) //n번째(vertex의 갯수) 갱신이었다면 음의 사이클이 발생한 것 -> 최대 n-1회만 사용될 수 있음
                    return {INF + 1};
                dist[d] = next_weight; // 갱신
                flag = false; // 갱신되었음을 표시
            }
        }
        if (flag) //더 이상 갱신되지 않았다면 더 탐색할 필요 없음
            break;
    }
    return dist;
}

int main() {
    int n, m, a, b, c;

    //입력
    cin >> n >> m;
    //m개의 간선에 대한 정보를 저장함 (from, to, weight) 인 간선 들이 m개
    vector<ti> edges(m); //간선 정보를 저장할 벡터 (그래프 관계보다는 간선 자체의 정보가 더 중요함)
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        edges[i] = {a, b, c}; //방향 그래프 {from , to , weight}
    }

    //연산
    vector<ll> ans = bellmanFord(n, m, 1, edges);

    //출력
    if (ans[0] == INF + 1) { //음의 사이클
        cout << -1;
        return 0; //종료
    }
    for (int i = 2; i <= n; i++)
        cout << ((ans[i] == INF) ? -1 : ans[i]) << '\n'; //경로 없는 경우 -1로 return
}