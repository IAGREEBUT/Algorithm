//
// Created by 이유정 on 2022/08/28.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    int n;
    cin >> n;
    vector<double> arr;
    arr.assign(n, 0);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    double max = arr[n - 1];

    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i] / max * 100; //double 넣어주지 않으면 0 이하는 다 0처리! 명심
    }

    cout.precision(15); //상대 오차에 대한 내용
    cout << (double) sum / n;


}