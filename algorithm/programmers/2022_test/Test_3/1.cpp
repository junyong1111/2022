#include <string>
#include <iostream>
#include <vector>

using namespace std;

int solution(int a, int b, int n) {
    int answer = 0;
    int temp  =0; 

    while(n>=a){
        answer += (n/a)*b; // 추가로 얻은 병 더해줌  
        temp = n%a;  //나머지 계산 
        n = (n/a)*b + temp; //나눈 값과 나머지값 더하기
    }

    return answer;
}