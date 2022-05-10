#include <iostream>
#include <string>
using namespace std;

int main(){
    int N;
    int temp = 0;
    int sum = 0;
    int cnt  = 0;
    int one ;
    int ten;
    cin >> N;
    int check = N;
    if(N==0){cnt =1; cout << cnt ; return 0 ;}
    //cout << 68 %10; // 1의 자리
    //cout << 68 /10; // 10의 자리
    else{
        while(check!=temp){ 
                one = N%10;
                ten = N/10;
                sum = one + ten;
                temp = one*10 + sum%10;
                cnt++;
                N=temp;
        } // while
    }
cout << cnt;

    return 0;
}