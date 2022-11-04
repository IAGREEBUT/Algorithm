// DP - TOP DOWN방식
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

    if (i == 1) return tri[1][1];
    if (i == 0 || j == 0) return 0;
    if (dp[i][j] > -1)
        return dp[i][j];

    return dp[i][j] = max(topDown(i - 1, j - 1), topDown(i - 1, j)) + tri[i][j];


}


int main() {

    int n;
    cin >> n;

    dp.assign(n + 1, vector<int>(n + 1, -1));
    tri.assign(n + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cin >> tri[i][j];
        }
    }


    /*
     * Top Down 방식
     *
     */
    int ans = -1;

    for (int i = 1; i <= n; i++) {
        if (ans < topDown(n, i)) ans = topDown(n, i);
    }


    cout << ans;


}