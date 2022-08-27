#include <iostream>
#include <vector>
#include <algorithm>
#define SIZE 20


using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("input.txt", "r", stdin);
    vector<int>W(SIZE/2, 0);
    vector<int>K(SIZE/2, 0);

    for(int i=0; i<SIZE/2; i++)
        cin >> W[i];
    
    for(int i=0; i<SIZE/2; i++)
        cin >> K[i];

    sort(W.begin(), W.end());
    sort(K.begin(), K.end());

    int AnswerW = 0;
    int AnswerK = 0;

    AnswerW = W[9] + W[8] + W[7];
    AnswerK = K[9] + K[8] + K[7];

    cout << AnswerW << " " << AnswerK <<"\n";

    return 0;
}