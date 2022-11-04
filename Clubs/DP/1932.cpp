// DP
// 1932- 정수 삼각형
// 실버 1

#include <iostream>
#include <vector>

using namespace std;

/*
 * 삼각형
 * ...
 *
 * (i-1, j-1) / (i-1, j) / (i-1, j+1)
 *         (i,j)
 *
 *
 *
 */

vector<vector<int>> dp;
vector<vector<int>> tri;


int topDown(int i, int j) {

    if (i == 1 && j == 1) return tri[1][1];
    if (i == 0 || j == 0) return 0;
    if (dp[i][j] >= 0)
        return dp[i][j];

    return dp[i][j] = max(topDown(i - 1, j - 1), topDown(i - 1, j)) + tri[i][j];


}


int main() {

    int n;
    cin >> n;

    dp.assign(n + 1, vector<int>(n + 1, 0));
    tri.assign(n + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cin >> tri[i][j];
        }
    }

    if (n == 1) {
        cout << tri[1][1];
        return 0;
    }

    /*
     * Bottom - up 방식
     * 알고 있는 제일 작은값 dp[1][1] 부터 마지막 줄까지 실행
     */
    int ans = -1;
    dp[1][1] = tri[1][1];
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + tri[i][j]; // 대각선 위 2가지 중 최대 + 자기자신이 가진 값

            if (i == n) { // n==1인 경우 탐색 불가 예외처리 필수
                if (ans < dp[i][j]) ans = dp[i][j];
            }

        }
    }



    cout << ans;


}