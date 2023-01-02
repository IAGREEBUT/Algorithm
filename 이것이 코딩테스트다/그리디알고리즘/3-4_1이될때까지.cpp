//
// Created by 이유정 on 2023/01/02.
//

#include <iostream>

using namespace std;

int main() {


    int n, k;
    int ans = 0;

    cin >> n >> k;

    while (n > 1) {

        if (n % k == 0) { //k가 2 이상이기만 하면 k로 나누는 것이 1을 빼는 것 보다 항상 빠르게 수를 감소시킨다 -> 그리디가 최적해를 보장하는 이유
            n /= k;
        } else {
            n--;
        }
        ans++;

    }

    cout << ans;

}