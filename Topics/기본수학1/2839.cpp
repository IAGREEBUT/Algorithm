/*
 * 백준 - 단계별 문제풀이 : 기본수학1
 * 2839번
 *
 * 설탕 배달
 * 상근이는 지금 사탕가게에 설탕을 정확하게 N킬로그램을 배달해야 한다. 봉지는 3킬로그램 봉지와 5킬로그램 봉지가 있다.
 * 상근이는 귀찮기 때문에, 최대한 적은 봉지를 들고 가려고 한다.
 * 상근이가 설탕을 정확하게 N킬로그램 배달해야 할 때, 봉지 몇 개를 가져가면 되는지 그 수를 구하는 프로그램을 작성하시오.
 *
 */

#include <iostream>

using namespace std;

int solution(int n) {

    int a, b, tmp;

    b = n / 5; //b가 최대일 때

    while (b >= 0) { //b를 1개씩 줄여가면서 유효검사

        tmp = n - b * 5;

        if (tmp % 3 == 0) {
            a = tmp / 3;
            return a + b;
        }

        b--;

    }
    return -1;


}


int main() {

    int n;
    cin >> n;

    cout << solution(n) << "\n";

}
