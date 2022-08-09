#include <iostream>
#include <vector>
#include <algorithm>
#define SIZE 20000001
#define SZ 10000000


using namespace std;

int main(){ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("input.txt", "r", stdin);
    int N = 0;
    cin >> N;
    vector<int>Arr(SIZE,0);
    // 주어진 정수의 크기만큼 배열을 미리 생성
   
    for(int i=0; i<N; i++){
        int temp = 0;
        cin >> temp ;
        if(temp<0){ //음수인 경우 따로 처리
            temp = temp *-1; 
            Arr[SZ+temp] = 1;
        }
        else
            Arr[temp] = 1;
    }

    int M = 0;
    cin >> M;

    vector<int>Answer(M,0);
    int idx = 0;
    for(int i=0; i<M; i++)
    {
        int temp = 0;
        cin >> temp;
         if(temp<0){
            temp = temp *-1;
            temp += SZ;
         }
        if(Arr[temp]==1)
            Answer[idx++] = 1;
        else
            Answer[idx++] = 0;   
    }
        // 해당 값이 있다면 정답 벡터에 1 삽입
    for(auto a : Answer)
        cout << a << " ";
    cout << "\n";
    return 0;
}