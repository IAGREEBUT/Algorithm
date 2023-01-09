//
// 1541번 - 잃어버린 괄호
//


#include <iostream>

using namespace std;

int main() {

    string equation;
    cin >> equation;
    equation += '+'; // 마지막에 기호를 하나 넣어 마지막 숫자까지 연산에 포함되도록 한다

    bool flag = false; // - 기호의 등장여부 (-기호가 한번 나오면 그 뒤에 나오는 수는 어떤 기호가 오든 전부 - 처리가 가능하다)
    string num = ""; // string인 숫자들을 끊어서 저장함
    int ans = 0;


    for (int i = 0; i <= equation.length(); i++) {

        char c = equation[i];

        if (c == '-' || c == '+') { //기호가 나오는 경우 (이전에 저장해뒀던 숫자들을 연산해줄 차례)

            // 이전에 -의 등장 여부에 따라 연산이 나뉨
            if (flag) {
                ans -= stoi(num);
            } else {
                ans += stoi(num);
            }

            if (c == '-') flag = true; // -기호가 나오면 "그 뒤로"(그 전까진 + 연산이라서 연산이 끝난 마지막줄에 써놔야함)  -연산 가능

            num = ""; //숫자 초기화

        } else { // 숫자인 경우
            num += c; // append
        }


    }

    cout << ans;


}