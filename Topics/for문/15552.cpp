/*
 * 백준 - 단계별 문제풀이 : for문
 * 15552번
 *
 * 빠른 A+B
 * 두 정수 A와 B를 입력받은 다음, A+B를 출력하는 프로그램을 작성하시오.
 *
 */

#include <iostream>
#include <vector>

using namespace std;

int main() {

    // 입출력이 빈번하게 일어나는 경우 다음을 따르면 빨라진다. (실제로는 x,알고리즘 풀때)
    // 1. endl 대신 "\n" 사용

    // 2.
    cin.tie(NULL); //cin , cout의 묶음을 풀어줌
    ios_base::sync_with_stdio(false); //c, c++버퍼를 분리


    vector<int> v;
    int n, a, b;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        v.push_back(a + b);
    }

    for (int i = 0; i < n; i++) {
        cout << v[i] << "\n";
    }


}