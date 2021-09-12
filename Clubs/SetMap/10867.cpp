//
// Created by 이유정 on 2021/09/12.
//

#include <iostream>
#include <set>

using namespace std;

int main() {
    int n, k;
    set<int> s;

    //입력
    cin >> n;
    while (n--) {
        cin >> k;
        s.insert(k);
    }

    //출력
    for (auto iter = s.begin(); iter != s.end(); iter++)
        cout << *iter << ' ';
}