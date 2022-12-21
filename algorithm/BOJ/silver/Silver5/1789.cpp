#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);

    ll S = 0;
    cin >> S;
    ll i = 1; //현재 n의 값
    ll answer = 0; // 총합
    int cnt = 0;
    

    while (1){
        answer += i; // 현재값 더하기 다음값
        if(answer>S){break;} // 정답을 넘어서면 멈춤
        cnt ++; // 정답을 넘어서지 않았다면 카운트 1 증가
        i++; // n값 증가
    }
    
    cout << cnt << "\n";

    return 0;
}