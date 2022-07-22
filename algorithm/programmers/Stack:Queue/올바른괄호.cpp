#include <iostream>
#include <vector>
#include <algorithm>

#define A 4
#define B 2

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // freopen("input.txt" , "r", stdin);

    vector<int>ScoreA(A,0);
    vector<int>ScoreB(B,0);
    for(int i=0; i<A; i++)
        cin >> ScoreA[i] ;
    for(int i=0; i<B; i++)
        cin >> ScoreB[i] ;
    sort(ScoreA.rbegin(), ScoreA.rend());
    sort(ScoreB.rbegin(), ScoreB.rend());
    int sum = 0;
    for(int i=0; i<A-1; i++){
        sum = sum + ScoreA[i];
    }
    for(int i=0; i<B-1; i++){
        sum = sum + ScoreB[i];
    }
    
    cout << sum << "\n";

    return 0;
}