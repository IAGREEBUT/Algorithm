//
// 2020 카카오 인턴십 - 보석쇼핑
//

#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

set<string> jewel;
map<string, int> jewel_cnt; //보석 , 갯수

vector<int> solution(vector<string> gems) {
    vector<int> answer;

    int size = gems.size(); //진열장에 있는 모든 보석의 수

    //보석의 종류
    for (int i = 0; i < size; i++) {
        jewel.insert(gems[i]);
    }

    //보석 종류의 갯수
    int jewel_num = jewel.size();

    int left = 0, right = 0; //투포인터
    int start = 1, end = size; //답 (시작, 끝) : 답은 1부터 시작해야하므로 +1씩
    jewel_cnt[gems[left]]++;//map에 첫번째 보석을 넣어둠

    while (left <= right && right < size) {

        if (jewel_cnt.size() == jewel_num) {
            //답 갱신
            if (end - start > right - left) { // 더 적은 구간이어야 답이 될 수 있음
                start = left + 1; //실제는 0부터 시작이지만, 답은 1부터로 시작해서
                end = right + 1;
            }


            //왼쪽을 줄여봄
            jewel_cnt[gems[left]]--;
            if (jewel_cnt[gems[left]] == 0) { //0개가 되면
                jewel_cnt.erase(gems[left]);//map에서 제거
            }
            left++;

        } else if (jewel_cnt.size() < jewel_num) {
            //오른쪽으로 가면서 보석을 추가함
            right++;
            if (right == size) break; //사이즈가 초과 될 수 있음을 방지
            jewel_cnt[gems[right]]++; //map에 추가된 보석을 넣기
        }

    }

    //리턴할 배열에 넣어줌
    answer.push_back(start);
    answer.push_back(end);

    return answer;
}


int main() {

    vector<string> gems = {"DIA", "RUBY", "RUBY", "DIA", "DIA", "EMERALD", "SAPPHIRE", "DIA"};

    //연산
    vector<int> ans = solution(gems);

    //출력
    cout << ans[0] << ' ' << ans[1];
}