//
// Created by 이유정 on 2022/09/01.
//

#include <iostream>
#include <vector>

using namespace std;

int selfNumber(int n) {

    string str = to_string(n);

    int num;

    for (int i = 0; i < str.length(); i++) {
        num = str.at(i) - '0'; // char into int

        n += num;

    }

    return n;

}


int main() {

    bool arr[10036] = {false}; //최댓값 notTrueNum = 9999 + 9 + 9 + 9 + 9 = 10035 이므로 크기가 10036이여야함
    //그리고 true로 전부 초기화는 안되더라...

    for (int i = 1; i <= 10000; i++) {
        int notTrueNum = selfNumber(i);
        arr[notTrueNum] = true; //selfNumber가 아닌 것들을 true로 변경
    }
    for (int i = 1; i <= 10000; i++) {
        if (!arr[i]) {
            cout << i << "\n";
        }
    }

}