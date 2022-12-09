#include <iostream>
#define MAX_SIZE 9

using namespace std;

int arr[MAX_SIZE];
bool isUsed[MAX_SIZE];

void NandM(int k, int n, int m);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r" ,stdin);

    int N = 0;
    int M = 0;
    cin >> N >> M ;
    NandM(0, N, M);

    return 0;
}

void NandM(int k, int n, int m){
    if(k==m){ // 정해진 수열과 같아질 경우 배열에 들어있던 값들 출력
        for(int i=0; i<m; i++)
            cout << arr[i] << " ";
        cout << "\n";
        return;
    }
    for(int i=1; i<=n; i++) //1부터 주어진 n까지 백트랙킹 시작
    { 
        if(isUsed[i]==false){ // 만약 해당 값이 사용되지 않았다면 상태 공간 트리에 추가
            arr[k] = i;  // 해당 값을 배열에 저장
            isUsed[i] = true; // 중복을 방지하기 위해서 방문 체크
            NandM(k+1, n, m); // 재귀적으로 호출
            isUsed[i] = false; // 백트랙킹을 해야하므로 다시 방문 체크 해제
        }
    }
}