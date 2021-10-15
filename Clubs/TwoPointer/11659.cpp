//
// 11659번 - 구간 합 구하기 4
// [구간합] 방법
//

#include <iostream>
#include <vector>

using namespace std;

vector<int> v;


vector<int> arrSum(vector<int> v, int n) {

    vector<int> sum(n, 0);
    sum[0] = v[0];
    for (int i = 1; i < n; i++) {
        sum[i] = sum[i - 1] + v[i];
    }
    /*
     * i - 1          /  i
     * 0부터 i-1까지의 합 /  0 부터 i까지의 합 ...
     */

    return sum;

}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);


    int n, m;
    cin >> n >> m;


    v.assign(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    vector<int> sum = arrSum(v, n);

    int start, end;
    while (m--) {

        //start - 1 인덱스 부터 end - 1의 인덱스 까지의 합은?  (얘는 1부터 시작, 우리 배열은 0부터 시작)
        //"0 ~ (end-1) 인덱스 까지의 합"  - "0 ~ (start - 1) "이전(-1)" 인덱스 까지의 합"
        // => sum[end-1] - sum[start - 2]
        cin >> start >> end;
        cout << sum[end - 1] - sum[start - 2] << "\n";

    }


}