//
// 11399번 - ATM
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    int n;
    cin >> n;

    vector<int> arr;
    arr.assign(n, 0);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end()); //오름차순 정렬(작은게 먼저)

    int num = n; // arr[i]가 더해지는 횟수 (뒤로 갈수록 한개씩 줄어든다)
    int ans = 0;
    for (int i = 0; i < n; i++) {

        ans += arr[i] * num--;

    }

    cout << ans;

}

