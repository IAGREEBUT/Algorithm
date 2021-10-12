//
// 10816번 - 숫자 카드 2
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;

//찾고자 하는 X를 "초과"하는 수가 처음으로 나오는 위치
int lowerBound(int left, int right, int target) {

    while (left <= right) {

        int mid = (left + right) / 2;

        if (v[mid] < target) {
            left = mid + 1;
        } else if (v[mid] >= target) {
            /*
             * v[mid]==target으로, target이 등장하는 mid를 찾은 경우에
             * mid위치의 왼쪽 부분에도 같은 수가 있는지 확인해야 한다.
             * 즉, left <-> mid(==target) <-> right
             * left와 mid사이를 탐색 해야하므로, right를 mid-1로 보내 : left right (구)mid  이렇게 여기를 탐색하는게 맞다.
             *
             */
            right = mid - 1;
        }

    }

    /*
     * target값 이상(같음포함)이던 마지막 mid값(가장작은mid index)이 최초의 tagert값 등장 인덱스인데,
     * target값 이상(v[mid] >= target)인 mid이 나오면 right를 mid-1(왼쪽으로 보내) 왼쪽을 탐색했다.
     * right = mid - 1이었으므로, 마지막 mid = right + 1이다.
     * 위의 조건에 둘다 걸리지 않거나 while문이 끝났다면, 탐색이 완료된 것이고
     * 그 시점의 target값 이상인 마지막 mid (right+1)이다.
     *
     */


    return right + 1;
}

//찾고자하는 X값 "이상"의 수가 최초로 나오는 위치 
int upperBound(int left, int right, int target) {

    while (left <= right) {

        int mid = (right + left) / 2;

        if (v[mid] <= target) {
            /*
            * v[mid]==target으로, target이 등장하는 mid를 찾은 경우에
            * mid위치의 왼쪽 부분에도 같은 수가 있는지 확인해야 한다.
            * 즉, left <-> mid(==target) <-> right
            * left와 mid사이를 탐색 해야하므로, right를 mid-1로 보내 : left right (구)mid  이렇게 여기를 탐색하는게 맞다.
            *
            */
            left = mid + 1;
        } else if (v[mid] > target) {
            right = mid - 1;
        }
    }

    /*
     * 왼쪽을 탐색할 때, target이 나오면 계속 왼쪽을 탐색 (left = mid + 1)
     * 그러다가 right=left(=mid)가 되면
     * left = mid + 1이 진행된다.
     * 그러면 이동 직전까지가 target이었다는 뜻이 되기 떄문에, 마지막 target 바로 다음이 된 left가 답
     * (or right + 1)
     */

    return left;

}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;

    cin >> n;
    v.assign(n, 0);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }


    //정렬
    sort(v.begin(), v.end());


    cin >> m;

    int num;
    while (m--) {
        cin >> num;

        //upperBound : 마지막으로 나온 num index의 + 1 (그다음) -> 찾고자 하는 X를 "초과"하는 수가 처음으로 나오는 위치
        //lowerBound : 최초로 나온 num의 index -> 찾고자하는 X값 "이상"의 수가 최초로 나오는 위치

        cout << upperBound(0, n - 1, num) - lowerBound(0, n - 1, num) << " ";

    }


}
