/*
 * 백준 - 단계별 문제풀이 : while문
 * 10952번
 *
 * A+B - 5
 * 두 정수 A와 B를 입력받은 다음, A+B를 출력하는 프로그램을 작성하시오.
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