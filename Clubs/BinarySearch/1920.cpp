//
// 1920 - 수 찾기
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;

//재귀
bool binarySearch(int left, int right, int n) {

    if (left > right) return false;

    int mid = (right + left) / 2;

    if (v[mid] == n) return true;
    else if (v[mid] < n) return binarySearch(mid + 1, right, n);
    else return binarySearch(left, mid - 1, n);

}

// while문 
bool binarySearch2(int left, int right, int target) {
    while (left <= right) { //left 포인터가 right 포인터보다 뒤에 있으면 break
        int mid = (left + right) / 2; //중간값
        if (v[mid] == target) //target을 찾음
            return true;
        if (v[mid] > target) //중간값이 target보다 크다면 target은 왼쪽에 있음
            right = mid - 1;
        if (v[mid] < target) //중간값이 target보다 작다면 target은 오른쪽에 있음
            left = mid + 1;
    }
    return false; //target을 찾지 못함
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    v.assign(n, 0);
    for (int i = 0; i < n; i++)
        cin >> v[i];


    //정렬
    sort(v.begin(), v.end());


    int m;
    cin >> m;

    int num;
    while (m--) {
        cin >> num;
        cout << binarySearch2(0, n - 1, num) << "\n";
    }


}