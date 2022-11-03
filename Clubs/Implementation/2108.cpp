// 구현
// 2108 - 통계학
// 실버 4

#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;
typedef pair<int, int> ii;

bool compare(ii a, ii b) {

    if (a.first == b.first) {
        return a.second < b.second; // 오름차순(작은거부터)
    }
    return a.first > b.first; //내림차순 (큰거부터)

}


int main() {

    int n;
    double sum = 0;
    cin >> n;


    vector<int> nums;
    nums.assign(n, 0);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
        sum += nums[i];
    }

    sort(nums.begin(), nums.end());


    vector<ii> arr;
    arr.push_back({1, nums[0]});
    int idx = 0;
    for (int i = 1; i < n; i++) {
        if (nums[i] == arr[idx].second) {
            arr[idx].first++;

        } else {
            idx++;
            arr.push_back({1, nums[i]});
        }
    }

    sort(arr.begin(), arr.end(), compare);


    cout << (round(sum / n) == -0 ? 0 : round(sum / n)) << "\n";
    cout << nums[floor(n / 2.0)] << "\n";
    cout << (arr[0].first == arr[1].first ? arr[1].second : arr[0].second) << "\n";
    cout << nums[n - 1] - nums[0] << "\n";


}



