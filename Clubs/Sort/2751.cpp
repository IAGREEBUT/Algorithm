//
// Created by 이유정 on 2022/08/17.
//

#include <iostream>
#include <vector>

using namespace std;

vector<int> arr; // 원본 배열
vector<int> res; // merge한 것을 저장해둘 배열 -> 꼭 전역변수로 설정할 것 아니면 매번 만들어주기 때문에 공간 복잡도가 커질 수 있다.

//병합 정렬
// 1. 추가 메모리가 필요하다 O(N)
// 2. 시간 복잡도 nlogn -> 어떠한 상황에서도 이를 보장한다

//
void merge(int left, int mid, int right) {

    /*
     * p1 : 왼쪽 배열의 첫번째 원소 인덱스
     * p2 : 오른쪽 배열의 첫번쨰 원소 인덱스
     * p3 : 정렬을 완료할 배열의 첫번째 원소
     */


    int p1 = left, p2 = mid + 1, p3 = left;

    while (p1 <= mid && p2 <= right) { // 왼쪽 배열, 오른쪽 배열중 어느하나라도 끝까지 탐색함
        if (arr[p1] < arr[p2])//두 배열의 원소들을 비교
            res[p3++] = arr[p1++];//더작은 쪽의 값을 넣고 인덱스 증가
        else
            res[p3++] = arr[p2++];
    }

    // 배열 두개중 하나에 원소가 아직 남아있을 때
    //1. 왼쪽 배열의 원소가 남은 경우
    while (p1 <= mid) {
        res[p3++] = arr[p1++];
    }

    //2. 오른쪽 배열의 원소가 남아있는 경우
    while (p2 <= right) {
        res[p3++] = arr[p2++];
    }

    for (int i = left; i <= right; i++) //res -> arr 복사
        arr[i] = res[i];

}


//devide
void mergeSort(int left, int right) { //devide 된 배열의 left,right(양끝)의 index
    int mid;

    //나눌 수 없을 때 까지 나누는 것을 반복
    if (left < right) {
        mid = (left + right) / 2; //중앙인덱스
        mergeSort(left, mid); // 왼쪽 배열
        mergeSort(mid + 1, right); // 오른쪽 배열


        //나누는 것이 끝나면 병합
        merge(left, mid, right);


    }
}


int main() {

    int n;

    cin >> n;
    arr.assign(n, 0);
    res.assign(n, 0);


    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    //연산
    mergeSort(0, n - 1);

    //출력
    for (int i = 0; i < n; i++)
        cout << arr[i] << '\n';


}