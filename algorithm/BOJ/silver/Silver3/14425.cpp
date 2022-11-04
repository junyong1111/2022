#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <map>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("input.txt", "r", stdin);

    int N,M = 0;
    cin >> N >> M;

    map<string,int>Map;

    for(int i=0; i<N; i++){
        string str;
        cin >> str;
        Map.insert(make_pair(str, 1));
    }
    string test;
    int answer = 0;    
    for(int i=0; i<M; i++){
        string str;
        cin >> str;
        if(Map[str]!=0){
            answer ++;
        }
    }

    cout << answer << "\n";

    return 0;
}