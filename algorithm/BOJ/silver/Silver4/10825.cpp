#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

typedef struct Studnet{
    string name;
    int KoreanScore;
    int EnglishScore;
    int MathScore;
}student;

bool com(student A, student B){
    if(A.KoreanScore>B.KoreanScore) //국어 성적 내림차순
        return true;
    if(A.KoreanScore == B.KoreanScore){ //국어 성적이 같다면
        if(A.EnglishScore<B.EnglishScore){return true;} //영어 점수 오름차순
        if(A.EnglishScore == B.EnglishScore){ //국어, 영어 점수가 같다면
            if(A.MathScore>B.MathScore){return true;} //수학 점수 내림차순
            if(A.MathScore==B.MathScore){ //국영수 점수 모두 같다면 사전순으로 정렬
                if(A.name <B.name){return true;}
            }
        }
    }
    
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("input.txt", "r", stdin);

    int N = 0;
    cin >> N ;

    string name;
    int KoreanScore;
    int EnglishScore;
    int MathScore;

    vector<student>V(N);

    for(int i=0; i<N; i++){   
        cin >> name  >> KoreanScore >> EnglishScore >> MathScore;
        V[i].name = name, V[i].KoreanScore = KoreanScore, V[i].EnglishScore=EnglishScore , V[i].MathScore=MathScore;
    }

    sort(V.begin(), V.end(), com);

    for(int i=0; i<N; i++){
        cout << V[i].name <<"\n";
    }
    
    return 0;
}