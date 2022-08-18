#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("input.txt", "r", stdin);

    int testCase = 0;
    cin >> testCase;

    while(testCase--){
        int Num = 0;
        cin >> Num;
        string Clothes;
        string Class;
        map<string, int>M;

        for(int i=0; i<Num; i++){
            cin >> Clothes >> Class;
            if(M.count(Class)==0){
                M.insert(make_pair(Class,1));
            }
            else{
                M.insert(make_pair(Class,M[Class]++));
            }
        }
        int answer = 1;
        for(auto m : M){
            answer *= m.second+1;
            //(a+1)*(b+1)*(c+1)....
        }
        answer --;
        // 옷을 아예 입지 않는 경우는 제외
        cout << answer << "\n";

    }
    return 0;
}
