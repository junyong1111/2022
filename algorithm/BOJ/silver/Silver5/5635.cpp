#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

typedef struct person{
    string name;
    int day;
    int month;
    int year;
}person;


bool com(person A, person B){
    if(A.year > B.year){
        return true;
    }
    if(A.year == B.year){
        if(A.month >B.month){return true;}
        if(A.month == B.month){
            if(A.day > B.day){return true;}
        }
    }
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("input.txt","r", stdin);

    int num = 0;
    cin >> num ;

    vector<person>P(num);
    person p;
    for(int i=0; i<num; i++){
        cin >> p.name >> p.day >> p.month >> p.year;
        P[i].name = p.name;
        P[i].day = p.day;
        P[i].month = p.month;
        P[i].year = p.year;
    }
    sort(P.begin(), P.end(), com);

    cout << P[0].name << "\n" << P[num-1].name <<"\n";
    return 0;
}