#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair<string,int> Student;

bool com(Student A, Student B){
    if(A.second == B.second){
        return A.first < B.first;
    }
    else{
        return A.second >B.second;
    }
}

int main(){ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("input.txt","r", stdin);

    int number = 0;
    cin >> number;
    cin.ignore();

    map<string,int>M;

    string name;
    for(int i=0; i<number; i++){
        cin >> name;
        cin.ignore();
        M.insert(make_pair(name,0));
    }
    
    string person;
    string str;
    for(int i=0; i<number; i++){
        getline(cin,str);
        int idx = 0;
        person = "";
        while(str[idx] != 0){
            if(str[idx] !=' '){
                person += str[idx];
                idx++;
            }
            else{
                M[person]++;
                person = "";
                idx++;
            }
        }
        M[person]++;
    }

    vector<Student>V(M.begin(), M.end());
    sort(V.begin(), V.end(),com);

    for(auto v : V){
        cout << v.first <<" "  << v.second <<"\n";
    }
    return 0;
}