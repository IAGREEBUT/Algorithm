//
// Created by 이유정 on 2022/10/13.
//


#include <iostream>

using namespace std;

/*
 * 수열이 오름차순 이기 때문에 이전에 탐색했던 인덱스 이후의 인덱스를 검사하면 되어서 check배열이 필요없다..
 */

const int SIZE = 9;

int n, m;
int arr[SIZE];


void backtracking(int cnt) {

    if (cnt == m) {
        for (int i = 0; i < m; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }

    for (int i = arr[cnt - 1] + 1; i <= n; i++) { // 그대신 이미 가진 숫자 이전보다 더 큰숫자부터 시작해야하
        //어쩌피 arr에 들어있는 숫자보다 큰 숫자만 들어가기 때문에 사용여부를 검사할 필요가 없다, 그보다 크면 사용된적이 없
        arr[cnt] = i;
        backtracking(cnt + 1);
    }


}


int main() {

    cin >> n >> m;

    for (int i = 1; i <= n; i++) { //맨처음 들어가는 숫자는 상관없기 때문에 여기서 처리해주고 cnt를 1부터 시작한다
        arr[0] = i;
        backtracking(1);
    }

}