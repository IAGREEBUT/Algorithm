//
//


#include <iostream>

using namespace std;

const int SIZE = 9;

int n, m;
int arr[SIZE];
bool checked[SIZE];


void backtracking(int cnt) {

    if (cnt == m) {
        for (int i = 0; i < m; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }


    for (int i = 1; i <= n; i++) {

        if (arr[cnt - 1] < i && !checked[i]) {//오름차순인 동시에 사용한적 없어야함(이 전 인덱스의 값이 새로 넣으려는 수보다 클 떄만)
            arr[cnt] = i;
            checked[i] = true;
            backtracking(cnt + 1);
            checked[i] = false; //원래대로 되돌려놓기
        }


    }


}

int main() {


    cin >> n >> m;


    for (int i = 1; i <= n; i++) { //맨처음 들어가는 숫자는 상관없기 때문에 여기서 처리해주고 cnt를 1부터 시작한다
        arr[0] = i;
        checked[i] = true;
        backtracking(1);
        checked[i] = false;
    }


}

