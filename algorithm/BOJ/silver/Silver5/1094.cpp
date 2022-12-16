#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int stick[7] = {64, 32, 16, 8, 4, 2, 1 };

int Stick(int target, int left , int right, int count);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 64 32 16 8 4 2 1 

    int targetLength = 0;
    cin >> targetLength;
    int answer = 0;
    for(int i=0; i<7; i++){
        if(stick[i]<=targetLength){
            answer += targetLength/stick[i];
            targetLength = targetLength%stick[i];
        }
    }
    cout << answer << "\n";
}