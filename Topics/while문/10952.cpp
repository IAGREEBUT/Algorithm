/*
 * 백준 - 단계별 문제풀이 : while문
 * 10871번
 *
 * X보다 작은 수
 * 정수 N개로 이루어진 수열 A와 정수 X가 주어진다. 이때, A에서 X보다 작은 수를 모두 출력하는 프로그램을 작성하시오.
 *
 */

#include <iostream>
#include <vector>

using namespace std;

int main() {

    int a, b;
    vector<int> res;

    while (true) {
        cin >> a >> b;

        if (a == 0 && b == 0) break;
        else res.push_back(a + b);
    }


    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << "\n";
    }
}