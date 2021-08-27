/*
 * 백준 - 단계별 문제풀이 : for문
 * 11021번
 *
 * A+B - 7
 * 두 정수 A와 B를 입력받은 다음, A+B를 출력하는 프로그램을 작성하시오.
 *
 */

#include <iostream>
#include <vector>


using namespace std;

int main() {
    int n, a, b;
    cin >> n;

    vector<int> v;

    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        v.push_back(a + b);
    }

    for (int i = 0; i < n; i++) {
        cout << "Case #" << i + 1 << ": " << v[i] << "\n";
    }
}