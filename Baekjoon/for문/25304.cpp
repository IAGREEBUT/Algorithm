//
// Created by 이유정 on 2022/08/31.
//

#include <iostream>

using namespace std;


int main() {

    int total, n;//총 금액, 산 물건의 종류 수
    int a, b;//물건 가격, 갯수

    cin >> total >> n;

    int sum = 0;

    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        sum += a * b;
    }

    if (sum == total) {
        cout << "Yes";
    } else {
        cout << "No";
    }

}