//
// Created by 이유정 on 2022/08/28.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;


int main() {

    int val;
    int num = 10;
    set<int> s;//set이 중복값을 허용하지 않는 점을 이용

    //10번 입력받음
    while (num > 0) {
        cin >> val;

        s.insert(val % 42);

        num--;
    }

    cout << s.size();


}