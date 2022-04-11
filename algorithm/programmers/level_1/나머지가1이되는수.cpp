#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    int x = 1;
    while(1){
        if(n%x == 1){
            return x;
        }
        x++;
    }
    return answer;
}