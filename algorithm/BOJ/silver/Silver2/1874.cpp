#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // freopen("input.txt", "r", stdin);
    int testCase = 0;
    cin >> testCase; 

    vector<int>Test(testCase, 0);
    stack<int>S;
    vector<char> answer;

    for(int i=0; i<testCase; i++)
        cin >> Test[i];

    int idx = 0;
    int S_idx = 1;
    S.push(S_idx);
    answer.push_back('+');
//커맨드 + 쉬프트 + L 
   
    while(!S.empty()){
        if(S_idx > testCase){
            break;
        }
        int temp = S.top();

        if(temp ==Test[idx]){
            answer.push_back('-');
            S.pop();
            idx++;
            if(S.empty()){
                if(S_idx <testCase)
                {
                    S.push(++S_idx);
                    answer.push_back('+');
                }
            }
        }
        else if(temp<Test[idx]){
            S.push(++S_idx);
            answer.push_back('+');
        }
        else{
            cout << "NO" <<"\n";
            return 0;
        }
    }
    for(auto &ans : answer) cout << ans <<"\n";

    return 0;
}