#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    int from,to = 0;
    int target = 0;
    
    for(int i=0; i< commands.size(); i++){
        vector<int>temp ;
        from = commands[i][0]-1;
        to = commands[i][1];
        target = commands[i][2]-1;
        // from , to , target 확인
        
        for(int k = from; k<to; k++)
            temp.push_back(array[k]);
        // 반복문을 이용하여 from ~ to 벡터 복사
        
        sort(temp.begin(), temp.end());
        // 정렬
        
        answer.push_back(temp[target]);
        // 원하는 인덱스 값 정답 벡터에 push
    }
    return answer;
}