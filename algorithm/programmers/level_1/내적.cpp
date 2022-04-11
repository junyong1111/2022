#include <string>
#include <vector>
#include <iostream>


using namespace std;

int solution(vector<int> a, vector<int> b) {
    int answer = 1234567890;
    int len = a.size();
    int sum = 0;
    for(int i=0; i<len; i++){
        sum = sum + (a[i] * b[i]);
    }
    answer = sum;
    
    return answer;
}