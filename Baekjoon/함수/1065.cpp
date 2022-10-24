//
// Created by 이유정 on 2022/09/01.
//

#include <iostream>
#include <vector>

using namespace std;


//한수인지 검사하는 함수
bool isHan(int n) {//최소 3자리 수

    string str = to_string(n);

    int a = str.at(0) - '0'; //이전 수
    int b = str.at(1) - '0'; // 그 다음 수
    int diff = a - b; //첫번째 수와 두번째 수의 차이

    a = b; // 이전 수를 교체


    for (int i = 2; i < str.length(); i++) {
        b = str.at(i) - '0';
        if (diff != (a - b)) return false; // 첫번째 수와 두번째수의 차이와 계속해서 같아야함
        a = b;
    }

    return true;


}

int main() {

    int n;
    cin >> n;

    if (n < 100) { cout << n; } //100보다 작은 수는 전부 한수
    else {
        int res = 99; //1~99 는 이미 한수
        for (int i = 100; i <= n; i++) {
            if (isHan(i)) res++;//한수인 경우마다 ++
        }
        cout << res;
    }


}
