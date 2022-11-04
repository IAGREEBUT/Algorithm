//
// 11053 - 가장 긴 증가하는 부분 수열
//

#include <iostream>
#include <vector>

using namespace std;

vector<int> arr;
vector<int> dp;

int main() {

    int n;
    cin >> n;

    arr.assign(n + 1, 0);
    dp.assign(n + 1, -1);


    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    dp[0] = 0;
    dp[1] = 1;

    int ans = 1; // 답 (가장 긴 증가하는 부분 수열의 길이)

    for (int i = 2; i <= n; i++) { // 2~n까지 각각의 부분수열의 길이
        int max = 0;//그중 최댓값(답)

        for (int j = 1; j <= i - 1; j++) { // 그 이전에 존재하는 원소중
            if (arr[i] > arr[j]) {//작은 것만 연속가능
                if (dp[j] > max) max = dp[j]; // 해당 작은 수가 가진 연속 부분수열의 길이
            }
        }
        dp[i] = max + 1;  // 자기자신 포함해서 1증가

        if (ans < dp[i]) ans = dp[i];
    }


    cout << ans;

}