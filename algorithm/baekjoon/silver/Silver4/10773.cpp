#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>


using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N ;
    cin >> N;
    stack<int> S;
    while(N--){
        int Num ;
        cin >> Num;
        if(Num ==0)
            S.pop();
        else
            S.push(Num);
    }
    long long Sum = 0;
    while(!S.empty())
    {
        long long temp = 0;
        temp = S.top();
        S.pop();
        Sum = Sum + temp;
    }
    cout << Sum  <<"\n";
    return 0;
}