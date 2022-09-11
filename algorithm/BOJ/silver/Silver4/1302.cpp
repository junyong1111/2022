#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("input.txt", "r", stdin);

    int number = 0;
    cin >> number;
    map<string, int>m;
    string str;
    for(int i=0; i<number; i++){
        
        cin >> str;
        if(m.count(str)==0){
            m.insert(make_pair(str, 1));
            
        }
        else{
            m.insert(make_pair(str, m[str]++));
        }

        
    }
    int max = 0;
    string answer;

    for(auto M : m){
        if(max < M.second){
            max = M.second;
            answer = M.first;
        }
    }

    cout << answer << "\n";

   

    return 0;
}
