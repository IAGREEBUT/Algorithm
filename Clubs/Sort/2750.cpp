//
// Created by 이유정 on 2022/08/16.
//
#include <iostream>
#include <vector>

using namespace std;

vector<int> swap(vector<int> arr, int left, int right) {
    int tmp = arr[left];
    arr[left] = arr[right];
    arr[right] = tmp;
    return arr;
}

vector<int> bubbleSort(vector<int> arr, int n) {
    /*
     * 인접한 두 원소를 비교
     * 오름차순 : (왼쪽)>(오른쪽)인경우 swap
     */

    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) { //왼쪽이 오른쪽보다 큰경우
            arr = swap(arr, i, i + 1);//swap
        }
    }

    return arr;


}


//오름 차순 정렬
int main() {

    int n;
    vector<int> arr;

    //들어올 변수의 갯수
    cin >> n;

    arr.assign(n, 0);// vector를 n칸으로 0을 넣어 초기화

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++) {
        arr = bubbleSort(arr, n);
    }

    for (int i = 0; i < n; i++) {
        cout << arr[i] << "\n";
    }

}

