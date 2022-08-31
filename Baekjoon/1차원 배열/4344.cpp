//
// Created by 이유정 on 2022/08/31.
//

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {

    int c;
    int n;
    double sum, avg, num;
    vector<int> arr;

    cin >> c;

    for (int i = 0; i < c; i++) {

        cin >> n;
        arr.assign(n, 0);

        sum = 0;// 평균을 구하기 위한 총점 계산

        for (int j = 0; j < n; j++) {
            cin >> arr[j];
            sum += arr[j];
        }
        avg = sum / n; // avg 구하기 (double주의)

        num = 0;
        for (int k = 0; k < n; k++) {
            if (arr[k] > avg) // 평균을 넘는(같은건 안된다)
                num++;//평균을 넘는 학생수 저장
        }


        //반올림 하여 3자리 수 까지 출력
        printf("%.3f", (double) num / n * 100);
        cout << "%\n";


    }


}