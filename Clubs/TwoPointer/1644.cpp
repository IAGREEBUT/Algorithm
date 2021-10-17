//
// 1644번 - 소수의 연속 합
//

#include <iostream>
#include <vector>

using namespace std;

//아레스토테네스의 체를 이용하여 n이하의 소수를 구함
//n까지 구하는 이유 : n이 소수인 경우 n 1개만으로도 표현가능하기 때문에
vector<bool> findPrimeNum(int n) {//n 이하인 모든 소수

    //소수인지 아닌지 bool
    vector<bool> is_prime(n + 1, true);//0 ~ n

    //초기 값 0,1 소수 아님
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= n; i++) {
        if (is_prime[i]) { // i가 소수면, i이후 i의 배수는 약수가 i이므로, 소수가 아님
            for (int j = i * i; j <= n; j += i)//j = j+i(i의 배수)
                is_prime[j] = false;
        }
    }

    /*
     * i*i 인 이유,
     * k ( k < i ), i * 1 ~ i * k 까지는 이미 검사 되었으므로, j 는 i * i에서 시작해도 된다.
     */

    return is_prime;

}


int main() {

    int n;
    cin >> n;

    vector<bool> is_prime = findPrimeNum(n);
    vector<int> prime;
    for (int i = 0; i <= is_prime.size(); i++) {
        if (is_prime[i]) prime.push_back(i);
    }


    int left = 0, right = 0; //투 포인터 (같은 위치에서 시작)
    int size = prime.size(); //배열의 크기
    int sum = prime[left]; //최초 값
    int ans = 0; //소수의 합으로 나타낼 수 있는 경우의 수
    while (left <= right && right < size) {

        if (sum == n) {
            ans++; // 갯수 1개 증가

            //다음 구간 탐색
            left++;
            right++;

            //구간의 합 재정비
            sum = sum + prime[right] - prime[left - 1];

        } else if (sum > n) { // 더한 값이 target값보다 크므로, 구간을 줄여야함
            sum -= prime[left]; //현재 구간이었던 부분을 제거하고
            left++;//구간 값 이동

        } else if (sum < n) { //더한 값이 target값 보다 작으므로, 큰 수를 포함시켜야함
            right++; // 구간을 증가시킴
            sum += prime[right];//증가시킨 값을 더함
        }

    }

    cout << ans;


}