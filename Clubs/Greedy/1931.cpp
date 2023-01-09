//
// 1931번 - 회의실 배정
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> ii;

//끝나는 시간이 빠른 순으로
//끝나는 시간이 같으면 더 짧은 회의를 하는 순서로
bool compare(ii a, ii b) {
    if (a.second == b.second) //회의 종료 시간이 같은 경우
        return a.first < b.first; //더 일찍 시작하는 회의를 배치해야함
    // -> why : 시작시간과 끝나는 시간이 같은 회의가 존재하기때문  1시-3시 / 3시 - 3시 회의 -> (이렇게 짜면 )둘다 선택가능! 근데 종료시간만 고려하면 한가지만 골라짐
    return a.second < b.second; // 작은 거 부터 (오름차순)
}


int main() {

    int n;
    cin >> n;

    vector<ii> arr;
    arr.assign(n, {0, 0});

    for (int i = 0; i < n; i++) {
        cin >> arr[i].first >> arr[i].second; //시작시간, 끝나는 시간
    }

    sort(arr.begin(), arr.end(), compare);

    int cnt = 0;

    int endpoint = 0; //직전 회의의 종료 시간

    for (int i = 0; i < n; i++) {

        if (arr[i].first >= endpoint) { // 시작시간이 직전 회의 종료시간보다 커야함
            cnt++;
            endpoint = arr[i].second;
        }
    }


    cout << cnt;

}