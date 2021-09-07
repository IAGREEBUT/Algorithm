//
// Created by 이유정 on 2021/09/07.
//

#include <iostream>
#include <vector>

using namespace std;
const int MAX_SIZE = 3;

//버킷
vector<vector<pair<string, int>>> bucket;

//해시 함수
int hashFunc(string str) {
    int key = 0;
    for (int i = 0; i < str.size(); i++)
        key += (str[i] - 'a') * i;
    return key % MAX_SIZE;
}

//버킷 상태 출력
void printHash() {
    for (int i = 0; i < MAX_SIZE; i++) {
        cout << "[ " << i << " ]";
        for (int j = 0; j < bucket[i].size(); j++) //bucket마다 사이즈가 다르기 때문에 .size()함수사용
            cout << " -> ( " << bucket[i][j].first << " " << bucket[i][j].second << " ";
    }

}

//학생 이름으로 점수 찾기
int findScore(string name) {

    int key = hashFunc(name);
    for (int i = 0; i < bucket[key].size(); i++) {
        if (bucket[key][i].first == name)
            return bucket[key][i].second;
    }
    return -1; // 입력받은 이름이 없는 경우도 리턴 값이 존재해야함.

}


//입력으로 주어지는 key는 중복이 없다고 가정
int main() {

    vector<pair<string, int>> student;
    student.emplace_back("lee", 42);
    student.emplace_back("kim", 100);
    student.emplace_back("lim", 75);
    student.emplace_back("park", 88);

    //2차우너 벡터 assign방법
    //low bucket의 MAX SIZE , column : 저장할 자료 (크기는 알 수 없음 동적임 = 0)
    bucket.assign(MAX_SIZE, vector<pair<string, int>>(0));

    for (int i = 0; i < student.size(); i++) {

        int key = hashFunc(student[i].first);
        cout << student[i].first << ' ' << key << '\n';
        bucket[key].push_back(student[i]);
    }
    printHash();

    string target = "lim";
    int score = findScore(target);

    if (score == -1)
        cout << "No Such Data\n";
    else
        cout << "Score of " << target << " : " << score << "\n";
}
