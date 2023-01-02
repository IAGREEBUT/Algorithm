//
// Created by 이유정 on 2023/01/02.
//

/*
 * 큰 수의 법칙
 *
 * 다양한 수로 이루어진 배열이 있을 때,
 * 배열의 크기는 n
 * 주어진 수들을 m번 더하여 가장 큰 수를 만드는 법칙이다.
 * 단, 배열의 특정 인덱스에 해당하는 수가 k번 초과해서 더해질 수 없다
 *
 */


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    int n, m, k;


    cin >> n >> m >> k;
    int m2 = m;

    vector<int> arr;
    arr.assign(n, 0);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    //내림차순으로 정렬
    sort(arr.begin(), arr.end(), greater<int>());

    int max_value = arr[0];
    int second_max = arr[1];

    //방법 1) 그리디 알고리즘으로 더해서 해결
    int ans = 0;
    int idx = 0;

    //m번 더하기
    while (m--) {

        ans += max_value;
        idx++; //k번 체크를 위해 몇번 연속으로 더했는지 확인해준다

        // m==0일 때가 last step이므로 m이 최소 1은 되어야 아래 연산을 진행가능
        if (m > 0 && idx == k) { // k번 연속으로 더해졌다면
            idx = 0; // 연속으로 더해진 횟수를 초기화
            ans += second_max; // 두번째로 큰 수를 1회 더해준다
            m--;// 1회 더해주었으므로 m을 감소시킨다
        }

    }

    cout << ans << "\n";


    //방법 2) 수학적 방법으로 해결

    /*
     * 가장 큰 수 : a
     * 두번쨰로 큰 수 : b
     *
     * a + a + a ... + b : a가 k개 , b가 1개 인 형태가 반복하여 더해짐 의
     *
     * k+1 길이의 수열이 반복해서 더해지는 형태
     *
     * 전체에서
     * m / (k + 1 ) <-해당 수열이 얼마나 반복되는가 ?
     * m / (k + 1 ) * k <- 전체에서 a가 얼마나 반복되는가 ( 해당 수열에서 k회 등장하므로 * k 임)
     *
     * 나누어 떨어지지 않는 경우 나머지는 전부 a임
     * m % (k+1)
     *
     * m - (a의등장 횟수) = b의 등장 횟수
     *
     *
     */

    int count = (m2 / (k + 1)) * k + m2 % (k + 1);

    int ans2 = count * max_value + (m2 - count) * second_max;

    cout << ans2;

}

