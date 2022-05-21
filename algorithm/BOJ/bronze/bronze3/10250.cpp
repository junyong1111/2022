#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); 

    int testCase = 0 ;
    cin >> testCase;

    while(testCase--){
        int H,W,N;
        int cnt = 0;
        cin >> H >> W >> N; 
        // 호텔의 층 수 , 각 층의 방 수 , 몇 번째 손님
        // 9 10 90
        int q,r;//몫과 나머지를 저장
        q = (N-1)/H; 
        r = (N-1)%H;
        int answer = (r+1) *100 + q+1;
        cout << answer <<"\n";

    }// testCase

    return 0;
}