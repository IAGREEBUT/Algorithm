//
// (별)
//

#include <iostream>

using namespace std;

const int SIZE = 16;

int n;
int ans = 0;


//하나를 놓았을 때 check 되어야 하는 부분이 3개임!
bool col[SIZE]; // 열 (n개)
// 대각선 오른쪽위 -> 왼쪽 아래 / 왼쪽위 -> 오른쪽 아래 :  임의로 각각의 대각선에 번호를 붙여서 생각하기

//n + (n-1) 개 (이유: 1칸 짜리 1줄 , 2칸짜리 1줄 ... n칸짜리 1줄... 2칸짜리 1줄, 1칸짜리 1줄..)
bool rtol[2 * SIZE]; // right top -> left bottom (row + col)이 값은 값끼리 같은 line
bool ltor[2 * SIZE]; // left top -> right bottom  (row - col)이 같은 값끼리 같은 line (but -가 포함되어 있으므로 + n해줘서 모두 양수로 변경필요)

void backtracking(int cnt) { //queen의 수 == 각 행의 idx (행당 1개만들어가기 때문)

    if (cnt == n) { //성공적으로 queen을 n개 배치했다면
        ans++; //정담(경우의 수를 증가시키고
        return;
    }

    for (int j = 0; j < n; j++) {
        if (!col[j] && !rtol[cnt + j] && !ltor[cnt - j + n]) {
            col[j] = true;
            rtol[cnt + j] = true;
            ltor[cnt - j + n] = true;
            backtracking(cnt + 1);
            col[j] = false;
            rtol[cnt + j] = false;
            ltor[cnt - j + n] = false;
        }


    }
}


int main() {

    cin >> n;

    //첫번째 말은 어디든 올 수 있음
    //첫번째 행 어디 열에서 시작할지만 정해주면됨
    backtracking(0);


    cout << ans;

}