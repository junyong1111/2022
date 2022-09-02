#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct subtask{
    int sub1;
    int sub2;
}subtask;

bool com(subtask a, subtask b){
    return a.sub2 < b.sub2;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("input.txt", "r", stdin);

    int number = 0; // 문제 갯수
    int task = 0; // 풀 수 있는 난이도 
    int possible =0; //풀 수 있는 문제 수

    cin >> number >> task >> possible;
    if(possible==0){
        cout << 0 ; 
        return 0;
    } // 문제를 하나도 못푸는 경우 예외처리

    vector<subtask>Apc;

    for(int i=0; i<number; i++){
        subtask s;
        cin >> s.sub1 >> s.sub2;
        Apc.push_back(s);
    } //sub task 입력 

    sort(Apc.begin(), Apc.end(), com); // sub2를 기준으로 오름차순 정렬
    int sum = 0; //총 합
    int cnt = 0; // 푼 문제 수 

    for(int i=0; i<number; i++){
        if(Apc[i].sub2<=task){  //만약 더 높은 점수를 주는 sub2를 풀 수 있다면 풀고 점수, 푼 문제수 추가
            sum = sum + 140;
            cnt ++;
        }
        else{ // sub2를 못 푼다면 
            if(Apc[i].sub1<=task){ // sub1을 풀 수 있는지 확인 후 풀 수 있다면 점수, 푼 문제수 추가
                sum =sum +100;
                cnt ++;
            }  
        }
        if(cnt == possible){break;} // 풀 수 있는 문제를 다 풀었다면 종료
    }

    cout << sum ; // 총합 출력
    return 0;
}