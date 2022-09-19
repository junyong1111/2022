#include <iostream>
#include <string>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("input.txt" , "r" ,stdin);

    int n = 0;
    cin >> n;
    int target = 0;
    cin >> target;
    int answer = 0;


    for(int i=1; i<=n; i++){
        string str = to_string(i);
        for(int j=0; j<str.length(); j++){
            if(str[j] == target+48){
                answer ++;
            }
        }
    }
    cout << answer << " " ;
    return 0;
}