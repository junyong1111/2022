#include <iostream>
#include <cmath>
#include <string>

using namespace std;

long long solution(int price, int money, int count)
{
    long answer = -1;
    long sum = 0;
    for(int i=1; i<=count; i++){
        sum = sum + (price *i);
    }
    answer = money - sum;
    if(answer >=0){
        answer = 0;
    }
    else{answer = answer * -1 ; return answer ;}
    return answer;
}