#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool com(string a, string b){
    return a>b;
} //사전순 정렬

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // freopen("input.txt", "r" ,stdin);

    int notListend = 0;
    int notSaw = 0;
    cin >> notListend >> notSaw;

    map<string ,int>Answer;
    vector<string>list;

    for(int i=0; i<notListend; i++){
        string str;
        cin >> str;
        Answer.insert(make_pair(str, i+1));
    }
    // 들어보지 못한 인물들을 map에 insert

    for(int i=0; i<notSaw; i++){
        string str;
        cin >> str;
        // 보지못한 인물들이 map에 있는지 확인 이때 만약 존재하지않는다면 0을 리턴해준다.
        if(Answer[str]!=0)
            list.push_back(str);
    }
    
    stable_sort(list.begin(), list.end());
    cout << list.size() <<"\n";
    for(vector<string>::iterator it = list.begin(); it!= list.end(); it++)
        cout << *it << "\n";
    return 0;
}