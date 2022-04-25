#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
vector<long long>ans(100,0); //이미 계산된 값을 저장하기 위한 벡터

int fib(int N){
    if(N<=1)
        return N;
    else{
        int idx = N-2;
        if(ans[idx]!=0){ //만약 이미 값이 저장되어있다면 그 값을 반환
            return ans[idx];
        }
        else{ // 값이 저장되어 있지않다면 값을 저장 
            ans[idx] = fib(N-2) + fib(N-1);
            return ans[idx];
        }
    }
}

int main(){ 
    int testCase = 0;
    cin >> testCase;

    while(testCase--){
        int N =0 ;
        cin >>N;
        int zero = 0;
        int one = 0;
        if(N==0){
            zero = 1;
        }
        else if(N==1){
            one = 1;
        }
        else{
            one = fib(N); //1이 나온횟수
            zero = fib(N-1); //0이 나온횟수
        }
        cout <<zero << " ";
       cout << one << "\n";
    }

    return 0;
}