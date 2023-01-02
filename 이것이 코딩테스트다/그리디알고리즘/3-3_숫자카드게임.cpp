//
// Created by 이유정 on 2023/01/02.
//

#include <iostream>
#include <vector>

using namespace std;

const int MAX = 10000;
vector<int> arr;

int main() {

    int n, m, v, min_v;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        min_v = MAX; //입력 끝날때마다 초기화

        for (int j = 0; j < m; j++) {
            cin >> v;

            if (min_v > v) {
                min_v = v;
            }
        }
        arr.push_back(min_v); // 해당 행에서 최소 값을 arr에 저장

    }


    sort(arr.begin(), arr.end(), greater<int>());


    cout << arr[0];


}