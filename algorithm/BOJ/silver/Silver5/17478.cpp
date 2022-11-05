#include <iostream>
#include <string>

using namespace std;

void WhatIsRecursion(int number);

int main(){
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("input.txt", "r", stdin);
    cout << "어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다."<<endl;
    WhatIsRecursion(1);

    return 0;

}

void WhatIsRecursion(int number){
    if(number <=1){
        cout << "재귀함수는 자기 자신을 호출하는 함수라네" <<"/n";
    }
}