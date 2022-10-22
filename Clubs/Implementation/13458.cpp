// <구현, 수학>
// 13458 - 시험 감독
//

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;
typedef long long ll;

int main() {

    int n, b, c, num;

    cin >> n;

    vector<int> test_room(n, 0);


    for (int i = 0; i < n; i++) {
        cin >> num;
        test_room[i] = num;
    }

    cin >> b >> c;


    ll ans = n; //총감독관 필수
    for (int i = 0; i < n; i++) {
        if (test_room[i] - b > 0)
            ans += ceil((test_room[i] - b) / (long double) c);
    }


    cout << ans;

}