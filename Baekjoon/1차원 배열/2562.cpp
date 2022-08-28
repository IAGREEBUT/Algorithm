//
// Created by 이유정 on 2022/08/27.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


bool compare(pair<int, int> a, pair<int, int> b) {
    return a.second > b.second; //두번째 값을 기준으로 내림차순 정렬
}


int main() {

    vector<pair<int, int>> arr;
    arr.assign(9, {0, 0});

    //입력받은 순서와 값을 pair로 저장
    for (int i = 0; i < 9; i++) {
        arr[i].first = i;
        cin >> arr[i].second;
    }

    sort(arr.begin(), arr.end(), compare);

    cout << arr[0].second << "\n" << arr[0].first + 1;


}