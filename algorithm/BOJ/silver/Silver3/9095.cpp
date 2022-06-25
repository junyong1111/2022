#include <iostream>

using namespace std;

// 문제에서 N은 11보다 작으므로 해당 테이블 생성
int DP[12];

int getDP(int N){
// 해당 테이블의 값이 있다면 그 값을 리턴
    if(DP[N]!=0)    
        return DP[N];
    else{
// 해당 테이블의 값이 없다면 1,2,3 테이블을 이용하여 갱신 후 반환
        DP[N] = getDP(N-1) + getDP(N-2) + getDP(N-3);
        return DP[N];
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

// 초기 1,2,3 테이블 갱신
    DP[0] = 0;
    DP[1] = 1;
    DP[2] = 2;
    DP[3] = 4;

    int testCase = 0;
    cin >> testCase ;
    
    while(testCase--){
        int Num = 0;
        cin >> Num;

        int answer = getDP(Num);
        cout << answer << "\n";
    }

    return 0;
}