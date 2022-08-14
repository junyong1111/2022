#include <string>
#include <queue>
#include <iostream>
#include <vector>

using namespace std;

int makeBurger(vector<int>&Answer, vector<int>&V, int Num){
    for(int i=0; i<4; i++){
        // cout << "V[num+i] : " << V[Num+i] << "\n";
        // cout << "Answer[i] : " << Answer[i] << "\n";
        if(V[Num+i] != Answer[i])
            return 0;
    }
    return 1;
}

int solution(vector<int> ingredient) {
    vector<int>Answer(4,0);
    int answer = 0;
    Answer[0] = 1;
    Answer[1] = 2;
    Answer[2] = 3;
    Answer[3] = 1;
//기준 벡터
    vector<int>V;
    vector<int>temp;
    for(auto i : ingredient){
        V.push_back(i);
    }
    // 벡터에 정보 입력

    int i = 0;
    while(V.size()>=i){ //남은 재료보다 인덱스가 넘어가면 멈춤 

        if(makeBurger(Answer, V,i)){ //햄버거를 만들 수 있는지 확인 
            answer ++; //만들 수 있으면 추가
            if(V.size()-i+4 <3) {break;} //남은 재료가 충분하지 않으면 멈춤
            for(int j=i+4; j<V.size(); j++){
                temp.push_back(V[j]); // 임시 벡터에 추가 
            }
            V.swap(temp); // 재료 벡터 갱신
            temp.clear();
            i = 0;
        }
        else{
            temp.push_back(V[i]);
        }
        i++;

    }
  
    return answer;
}