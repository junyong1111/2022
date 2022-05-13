#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    while(true)
    {
        string str;
        stack<char>world;
        bool check = false;
        getline(cin , str);
        if(str[0]=='.'){break;}// 첫 입력이 '.'라면 반복 종료 
        for(int i=0; str[i]!='.'; i++){ // 마침표가 나오기 전까지 확인
            switch(str[i]){
                case '(':
                    world.push(str[i]); //열린 괄호가 나온다면 스택에 푸쉬
                    break;
                case '[':
                    world.push(str[i]); //열린 괄호가 나온다면 스택에 푸쉬
                    break;
                case ')': //닫힌 괄호가 나왔을때 스택이 비어있지않고(같은 괄호가 한 쌍) , 이전에 들어온 괄호랑 짝이 맞으면 팝
                    if(world.empty()){check = true; break;} // 쌍이 아닌경우
                    if(world.top() != '('){check = true; break;} // 같은 종료의 괄호가 아닌 경우
                    world.pop();
                    break;
                case ']': //닫힌 괄호가 나왔을때 스택이 비어있지않고(짝이 맞고) , 이전에 들어온 괄호랑 짝이 맞으면 팝
                    if(world.empty()){check = true; break;}
                    if(world.top() != '['){check = true; break;}
                    world.pop();
                    break;
            } //switch 
        } // 마침표전까지 문자열을 검사하는 for문
        if(world.empty() && check == false){
            cout << "yes\n" ;
        } //정상적으로 끝난경우
        else{
            cout << "no\n";
        }
    }
    return 0;
}
