#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int main(){
    int N;
    cin >> N;
    int cnt = 0;
    int sum  = 0;
    int *arr = new int[N];
    string str;
    for(int i=0; i<N; i++){
        cin >> str;
        for(int j=0; j<str.length(); j++){
            if(str[j]=='O'){cnt++; sum = cnt+sum; }
            else{cnt = 0;}
        } 
        arr[i]=sum;
        sum = 0;
        cnt = 0;
    }
    for(int i=0; i<N ;i++){
        cout << arr[i]<<endl;
    }
    return 0;
}