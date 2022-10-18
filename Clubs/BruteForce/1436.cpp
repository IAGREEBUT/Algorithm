//
// Created by 이유정 on 2022/10/08.
//

#include <iostream>

using namespace std;


int solution(int n){

    int cnt=0;

    for(int i=666; ; i++){

        string s = to_string(i);

        if(s.find("666") != s.npos)//666이 내부에 존재
            cnt++;

        if(cnt == n) return i;

    }

}


int main(){

    int n;
    cin>>n;

    cout<<solution(n);


}