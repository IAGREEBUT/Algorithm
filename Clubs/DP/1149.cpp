//
// 1149번 - RGB 거리
// 실버 1

#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

vector<vector<int>> dp;
vector<vector<int>> paint;

int main() {


    int n;
    cin >> n;

    dp.assign(3, vector<int>(n, 0));
    paint.assign(3, vector<int>(n, 0));


    for (int i = 0; i < n; i++) {
        cin >> paint[0][i] >> paint[1][i] >> paint[2][i]; //빨 > 초 > 파
    }

    //첫번째 집이 각각 빨/초/파를 선택한 경우가 기본값
    dp[0][0] = paint[0][0];
    dp[1][0] = paint[1][0];
    dp[2][0] = paint[2][0];

    //앞집과 겹치지 않게 색칠
    for (int i = 1; i < n; i++) {

        dp[0][i] = min(dp[1][i - 1], dp[2][i - 1]) + paint[0][i];
        dp[1][i] = min(dp[0][i - 1], dp[2][i - 1]) + paint[1][i];
        dp[2][i] = min(dp[1][i - 1], dp[0][i - 1]) + paint[2][i];

    }

    //그 중 최솟값
    cout << min({dp[0][n - 1], dp[1][n - 1], dp[2][n - 1]});


}

