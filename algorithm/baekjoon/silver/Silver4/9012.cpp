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
        stack<char>S;
        string str;
        cin >> str;
        check = false;
        for(int i=0; i<str.length(); i++)
        {
            if(str[i] == '(') //열괄
            {
                S.push(str[i]); 
                check = true;
            }
                
            else
            {   
                if(S.empty()){check = false; break;} 
                S.pop();
            } // 닫괄
            
        }
        if(S.empty() && check == true)
            ans = "YES";
        else
            ans = "NO";
        cout << ans <<"\n";
        
    }
    
    
    
    return 0;
}