//
// 프로그래머스 - 2021 카카오 블라인드 리쿠르트 합승 택시 요금 (Lv.3)
// https://school.programmers.co.kr/learn/courses/30/lessons/72413
//

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
const int INF = 1e6 * 2;

/*
 * single source에서 시작하여
 * 특정 destination에 도착한다
 *
 * single source -> single destination
 * sigle source -> two different destination
 * 3가지의 합이 최소 ..
 *
 * ASP?
 *
 */

void floydWarshall(int vertex, vector<vector<int>> &dist) {


    for (int k = 1; k <= vertex; k++) {
        for (int s = 1; s <= vertex; s++) {
            for (int d = 1; d <= vertex; d++) {

                int cost = dist[s][k] + dist[k][d];
                dist[s][d] = min(dist[s][d], cost);


            }
        }
    }

}


int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = INF;

    vector<vector<int>> dist;
    dist.assign(n + 1, vector<int>(n + 1, INF));

    for (int i = 1; i <= n; i++) {
        dist[i][i] = 0;//자기자신 -> 자기자신 = 0
    }

    for (int i = 0; i < fares.size(); i++) {

        int from = fares[i][0];
        int to = fares[i][1];
        int cost = fares[i][2];

        //중요! 양방향 그래프임을 잊지말기 !!
        dist[from][to] = min(cost, dist[from][to]);
        dist[to][from] = min(cost, dist[from][to]);

    }

    floydWarshall(n, dist);


    for (int k = 1; k <= n; k++) {
        int cost_both = dist[s][k];
        int cost_a = dist[k][a];
        int cost_b = dist[k][b];
        answer = min(answer, cost_both + cost_a + cost_b);
    }


    return answer;
}


int main() {
    vector<vector<int>> fares = {{4, 1, 10},
                                 {3, 5, 24},
                                 {5, 6, 2},
                                 {3, 1, 41},
                                 {5, 1, 24},
                                 {4, 6, 50},
                                 {2, 4, 66},
                                 {2, 3, 22},
                                 {1, 6, 25}};
    int ans = solution(6, 4, 6, 2, fares);
    cout << ans;
}