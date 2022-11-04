// DP
// 15624번 - 피보나치 수 7
//

/*
 *
 *
 */

#include <iostream>
#include <vector>

using namespace std;

const int SIZE = 1000000;
vector<int> dp;

int fib(int n) {

    if (n == 0) return 0;
    if (n == 1) return 1;

    return fib(n - 1) + fib(n - 2); // n이 커지면 함수의 호출 횟수가 매우 많아 시간초과

}


/*
 * Top - down : 재귀 함수
 * 문제를 n이라는 가장 큰 문제에서 부터 시작
 * 작은 문제로 쪼개가며 문제를 해결
 */
int fibDPtopDown(int n) {

    if (n <= 1)
        return n;//기저조건

    if (dp[n] != -1) //이미 계산한 적이 있어서 존재
        return dp[n]; //


    return dp[n] = fibDPtopDown(n - 1) + fibDPtopDown(n - 2);

}


/*
 * Bottom - up : 더 효율적
 * 문제를 가장 작은 단위 부터 시작  (0&1)
 * n까지 단위를 키워가며 문제를 해결함
 */
int fibDPbottomUp(int n) {

    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];

}


int main() {

    dp.assign(SIZE + 1, -1);

    int n;
    cin >> n;

//    cout << fibDPbottomUp(n) % 1000000007 << "\n";
    cout << fibDPtopDown(n) % 1000000007 << "\n";

}