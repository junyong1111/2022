#include <iostream>
#include <vector>
#include <algorithm>
#include <string>


using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("input.txt", "r", stdin);

    int Num = 0;
    cin >> Num;
    bool check = false;
    
    string str[Num];
    string answer = "";
    
    for(int i=0; i<Num; i++)
        cin >> str[i];

    if(Num == 1){
        answer = str[0];
        cout << answer << "\n";
        return 0;
    }
    // N이 1인경우 예외조건
    
    for(int i=0; i<str[0].length(); i++){
        char temp = str[0][i];

        for(int j=1; j<Num; j++){
            if(temp == str[j][i]){
                check = true;
            }
            else{check = false; break;}
        }
        if(check == true){
            answer += temp;
            check = false;
            // 모두 일치한다면 추가
        }
        else{answer += '?';}
        // 하나라도 다르다면 ? 추가
    }

    cout << answer << "\n";
    

    return 0;
}