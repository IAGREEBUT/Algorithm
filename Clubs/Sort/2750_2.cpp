//
// Created by 이유정 on 2022/08/17.
//

#include <iostream>
#include <vector>

using namespace std;

//개선된 버블정렬
vector<int> bubbleSort(vector<int> arr, int n) {

    bool flag = false;
    int tmp;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
                flag = true;
            }
        }
        //한줄을 다 검사했는데도 swap이 0번 일어났다면 (flag still false) -> 이미 정렬이 되어있는 상태 (종료)
        if (!flag) return arr;
        flag = false; //true로 바뀌었다면 falsg로 다시 바꾸기
    }

    return arr;

}




int main() {

    int n;
    vector<int> arr;

    cin >> n;
    arr.assign(n, 0);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    arr = bubbleSort(arr, n);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << "\n";
    }

}