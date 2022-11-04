// 구현, 시뮬, 브루트포스, 백트레킹, 비트마스킹
// 17281번 - ⚾
// 골드 4

#include <iostream>
#include <vector>


using namespace std;

vector<vector<int>> hit; // 각 이닝에 대한 타자의 결과
vector<bool> field; // 루의 상황
vector<int> order; // 타자의순서를 저장
vector<bool> check; //백트레킹을 위한 check(어떤 선수들이 사용되었나)
int n, ans;//이닝의수, 답(최고점수)


//각각 타자에 대한 점수 계산
int first() { //안타
    int sum = 0;


    for (int i = 3; i >= 1; i--) {
        field[i] = field[i - 1];
    }
    field[0] = true; //타자가 1루로 이동

    if (field[3]) {
        field[3] = false;
        sum++;
    }

    return sum;

}


int second() {//2루타

    int sum = 0;

    //2,3루에 있던 애들은 점수됨
    if (field[2]) {
        field[2] = false;
        sum++;
    }
    if (field[1]) {
        field[1] = false;
        sum++;
    }

    if (field[0]) {//1루-> 3루로 이동
        field[2] = true;
        field[0] = false;
    }


    field[1] = true; //타자 2루로 이동

    return sum;


}


int third() {//3루타
    int sum = 0;
    for (int i = 0; i < 3; i++) {
        if (field[i]) {
            sum++;
        }
    }

    field.assign(4, false);//전부 false
    field[2] = true;

    return sum;
}


int homerun() { // 홈런
    int sum = 0;
    for (int i = 0; i < 3; i++) {
        if (field[i]) sum++;
    }

    field.assign(4, false);//전부 false
    return sum + 1; //타자까지 홈에 들어갈 수 있으므로 +1

}

//order배열이 완성(주자를 배치완료) 되면 해당 order에 따른 점수 계산 함수
int play() {


    int out = 0; //이닝 당 아웃당한 수
    int inning = 0;//몇번째 이닝인지
    int score = 0; // 점수
    int idx = 0;// 몇번째 순서인지

    while (inning != n) { //이닝을 다 채우면 종료 (같아지면 종료)

        int shot = hit[inning][order[idx]]; //이번 이닝, 이번 순서 타자의 결과

        //결과별 점수 합산
        if (shot == 0) out++;
        else if (shot == 1) score += first();
        else if (shot == 2) score += second();
        else if (shot == 3) score += third();
        else if (shot == 4) score += homerun();

        // 다음 순서 타자
        idx = (idx + 1) % 9;  //9번이되면 0번으로 돌아가야함


        //3아웃 되는 순간 이닝 교체
        if (out == 3) {
            out = 0;//아웃 초기화
            inning++; //다음 이닝으로
            field.assign(4, false); //필드 초기화
        }


    }

    return score;


}


//주자를 어떤 순서로 배치할지 -> 백트레킹 사용
void backtracking(int cnt) { // cnt번째 설 타자를 정함


    if (cnt == 3) {//4번(3)타자는 이미 정해졌으므로 패스
        backtracking(cnt + 1);
        return;
    }

    if (cnt == 9) {//기저 조건 (모든 선수를 다 사용함) -> 순서가 모두 정해짐
        int score = play();//점수계산
        ans = max(score, ans);//최대값 갱신
        return;
    }

    //order배열에 타자 배치
    for (int i = 1; i < 9; i++) { // 1번타자(0)은 이미 사용되었음 -> 가지고 있는 타자들 중에서
        if (!check[i]) { // 안사용한 타자들 중에서
            check[i] = true; //i타자를 사용
            order[cnt] = i; //cnt순서에 i타자 배치
            backtracking(cnt + 1); //다음 순서 정하기 (백트레킹)
            check[i] = false; //해제
        }

    }


}


int main() {

    cin.tie(NULL); //cin , cout의 묶음을 풀어줌
    ios_base::sync_with_stdio(false); //c, c++버퍼를 분리


    cin >> n;

    hit.assign(n, vector<int>(9, 0));
    field.assign(4, false);
    order.assign(9, 0);
    check.assign(9, false);


    order[3] = 0; //4번 타자는 항상 1번 타자
    check[0] = true; // 1번타자 이미 사용

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 9; j++)
            cin >> hit[i][j];
    }


    backtracking(0); //0번 순서 타자부터 정하기

    cout << ans;
}