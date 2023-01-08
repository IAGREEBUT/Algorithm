//
// 11047 번 - 동전 0
// "동전의 조건이 특별"해서 동적 프로그래밍보다 빠르게 답을 찾을 수 있는 문제
// 동전 Ai의 금액은 (1 ≤ Ai ≤ 1,000,000, A1 = 1, i ≥ 2인 경우에 Ai는 Ai-1의 배수) -> 배수기 때문에 금액이 큰 동전은 무조건 금액이 작은 동전의 합으로 이루어질 수 있음
//

#include <iostream>
#include <vector>

using namespace std;

int main() {

    int n, k;

    cin >> n >> k;

    vector<int> arr;
    arr.assign(n, 0);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int idx = n - 1;
    int ans = 0;

    while (true) {

        ans += k / arr[idx]; // 동전의 수
        k %= arr[idx--]; // 남은 금액 계산

        if (k == 0) break; //남은 금액이 0원이면



    }

    cout << ans;


}