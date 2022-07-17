#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("input.txt", "r", stdin);
    priority_queue<int, vector<int> >pq;
    int testCase = 0;
    cin >> testCase;
    while(testCase--){
        int Num = 0;
        if(Num<0){continue;} // 자연수가 아니라면 제외
        cin >> Num;
        if(Num!=0)
            pq.push(Num);
        else{
            if(pq.empty())
                cout << 0 <<"\n";
            else{
                cout << pq.top() <<"\n";
                pq.pop();
            }
        }
    }

    return 0;
}