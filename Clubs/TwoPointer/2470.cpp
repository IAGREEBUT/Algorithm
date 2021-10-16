//
// 2470번 - 두 용액
// [투 포인터]

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> liquid;

int main() {

    int n;
    cin >> n;

    liquid.assign(n, 0);
    //용액을 저장
    for (int i = 0; i < n; i++) {
        cin >> liquid[i];
    }

    //투 포인터 (양끝에서 시작)
    int left = 0, right = n - 1;
    int min_mix = 2 * 1e9 + 1; // 용액 하나에 최대 10억이므로, 2개를 더했을 때 최대값은 20억 (+1하면 절대 나올 수 없는 최댓값)

    sort(liquid.begin(), liquid.end()); //오름 차순 정렬

    int mix; // 두 용액을 섞은 값 저장
    int ans1 = left, ans2 = right; //답이될 인덱스
    while (left < right) {
        mix = liquid[left] + liquid[right]; //용액을 섞음


        if (abs(mix) < min_mix) { //0과 가까운 값 갱신(절댓값 사용)
            min_mix = abs(mix); //절댓값으로 저장하는 것 주의
            ans1 = left;
            ans2 = right;
        }

        if (mix == 0) break; //0이면 종료
        else if (mix < 0) {//0보다 작은 경우 -> 오름차순 정렬이므로, left++할수록 커짐
            left++;
        } else if (mix > 0) {
            right--;// right --될 수록 작아짐
        }

    }


    cout << liquid[ans1] << " " << liquid[ans2];

}
