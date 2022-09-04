#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct Asia{
    int CountryNumber;
    int StudentNumber;
    int SuudentScore;
}Asia;

bool com(Asia A, Asia B){
    return A.SuudentScore > B.SuudentScore;
    // 점수를 기준으로 내림차순 정렬
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("input.txt","r", stdin);

    int number = 0;
    cin >> number;

    vector<Asia>V(number);

    for(int i=0; i<number; i++){
        cin >> V[i].CountryNumber >> V[i].StudentNumber >> V[i].SuudentScore;
    }

    sort(V.begin(), V.end(), com);
    vector<int>Cnt(10000,0);
    // 국가별 인원수 체크를 하기 위한 배열

    int idx = 0;
    int anscnt = 0;


    while(anscnt!=3){ 
        Cnt[V[idx].CountryNumber]++; //국가별 인원 확인 
        if(Cnt[V[idx].CountryNumber] <=2 ){  //2명 이하면 출력 
            cout << V[idx].CountryNumber << " " << V[idx].StudentNumber <<  "\n";
            idx++;
            anscnt++;
        }
        else
            idx++;
    }

    return 0;
}