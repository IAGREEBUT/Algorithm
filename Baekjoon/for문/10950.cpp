/*
 * 백준 - 단계별 문제풀이 : for문
 * 10950번
 *
 * A+B - 3
 * 두 정수 A와 B를 입력받은 다음, A+B를 출력하는 프로그램을 작성하시오.
 *
 */

#include <iostream>
#include <vector>

using namespace std;

int main() {

    int n, a, b;

    vector<int> v;

    // 몇회 반복할지
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        v.push_back(a + b);
    }

    for (int i = 0; i < n; i++) {
        cout << v[i] << endl;
    }

    return 0;
}