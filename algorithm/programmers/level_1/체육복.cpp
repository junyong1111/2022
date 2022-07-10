#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<int>Student(n, 1);
    
    int move[2] = {-1,1};
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());
    
    
    for(int i=0; i<reserve.size(); i++)
        Student[reserve[i]-1] ++;

    for(int i=0; i<lost.size(); i++)
        Student[lost[i]-1] --;
    
    
    
    for(int i=0; i<n; i++){
        if(Student[i] == 2) //체육복의 여벌이 존재하는경우 앞뒤 확인
            for(int j=0; j<2; j++){ //앞뒤 홧인
                int temp = i+move[j]; //앞,뒤 이동
                if(temp >=0 && temp <n){ //인덱스 범위내
                    if(Student[temp] == 0 && Student[i] ==2){ //체육복이 필요하다면
                        //양 옆을 빌려줄때를 대비해서
                        Student[i] --; //내꺼 하나빼고 친구 하나 주기
                        Student[temp]++;
                    } //체육복 필요 _if
                } //범위_if
        } //앞뒤확인_For
    } //전체 학생확인_For
    for(int i=0; i<n; i++){
        if(Student[i] !=0){
            answer ++;
        }
    }
    return answer;
}


/* 
조건문을 통과할 때 
여분의 체육복을 가진 사람이 자신의 모든 체육복을 앞 뒤로 빌려주는경우가 발생했다
따라서 조건문을 자신의 체육복이 여분이 있으면서 체육복이 필요한 친구한테 빌려주는 조건을 추가하여 해결했다.
*/