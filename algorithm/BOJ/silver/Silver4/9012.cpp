#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int Num = 0;
    bool check = false;
    cin >> Num;
    string ans;
    while(Num--)
    {
        stack<char>S;  // 스택생성
        string str;
        cin >> str;
        check = false;
        for(int i=0; i<str.length(); i++)
        {
            if(str[i] == '(') //열린괄호이면 스택에 푸쉬 하고 정상종료 true
            {
                S.push(str[i]); 
                check = true;
            }
                
            else //닫힌괄호인데 이미 스택이 비어있으면 오류종료 false 후 break 그게 아니라면 스택에서 pop
            {   
                if(S.empty()){check = false; break;} 
                S.pop();
            } 
            
        }
        if(S.empty() && check == true) 
            ans = "YES";
            //스택이 정상종료 되었으면서 비어있다면 쌍이 맞음
        else // 스택이 비정상종료 또는 비어있지않다면 쌍이 맞지 않음
            ans = "NO";
        cout << ans <<"\n";   
    }
    return 0;
}