// 동적계획법
// 2579번 - 계단 오르기
// 실버 3

#include <iostream>
#include <vector>

using namespace std;

/*
 * 1칸 / 2칸
 * 연속 3칸 금지 ..
 */

vector<int> steps;
vector<int> dp;

int countScore(int n) {

    for (int i = 3; i <= n; i++) {
        dp[i] = max(dp[i - 3] + steps[i - 1], dp[i - 2]) + steps[i];
    }

    /*
     * 3연속 금지 == 최대 2연속만 가능
     * 2칸 : 2연속 발생확률 0
     *                        n-3 n-2 n-1 n
     * 1칸 : 2연속 선택시만 발생 == O    X   O  O (유일한 가능상황)-> 3번째 전 최대 + 직전점수 dp[n-3] + steps[n-1]
     *
     */

    return dp[n];

}


int main() {

    int n;
    cin >> n;

    dp.assign(n + 1, -1);
    steps.assign(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        cin >> steps[i];
    }

    dp[0] = 0;
    dp[1] = steps[1];
    dp[2] = steps[1] + steps[2];


    cout << countScore(n);


}