//
// Created by 이유정 on 2022/08/31.
//

#include <iostream>
#include <algorithm>

using namespace std;


int allSame(int v) {
    return 10000 + v * 1000;
}

int doubleSame(int v) {
    return 1000 + v * 100;
}

int fail(int a, int b, int c) {
    int v = max({a, b, c});
    return v * 100;
}


int main() {

    int a, b, c;

    cin >> a >> b >> c;

    /*
     * 1. 3개 다 같은 경우 (1가지)
     *      a==b==c
     *
     * 2. 2개가 같은 경우 (3가지)
     *      a==b != c
     *      a==c != b
     *      b==c != a
     *
     * 3. 3개 다 다른 경우 (1가지)
     *      a!=b!=c
     *
     *
     */
    int res;

    if (a == b) {
        if (a != c) {
            res = doubleSame(a);
        } else {
            res = allSame(a);
        }

    } else if (a == c) {
        if (a != b) {
            res = doubleSame(a);
        } else {
            res = allSame(a);
        }
    } else if (b == c) {
        if (b != a) {
            res = doubleSame(b);
        } else {
            res = allSame(a);
        }
    } else {
        res = fail(a, b, c);
    }


    cout << res;

}