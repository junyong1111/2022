#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct conference{
    int start;
    int end;
}conference;

bool com(conference a, conference b){
    if(a.end < b.end)
        return true;
    if(a.end ==b.end){ 
        //else if로 하면 segment falut뜸 ... 왜 그럴까
        return a.start < b.start;
    }
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // freopen("input.txt", "r", stdin);

    int Num = 0;
    cin >> Num;

    conference C ;
    vector<conference>Answer;

    for(int i=0; i<Num; i++){
        cin >> C.start >> C.end;
        Answer.push_back(C);
    }

    sort(Answer.begin(), Answer.end(), com);
    // 종료시점을 기준으로 정렬
    
    int temp = 0;
    int answer = 1;
    temp =Answer[0].end;
    
    for(int i=1; i<=Num; i++){
        // 종료시간보다 같거나 느린 시작시간이 있다면 갱신
        if(temp <= Answer[i].start){
            answer ++;
            temp = Answer[i].end;
        }
    }
    cout << answer << "\n";

    return 0;
}