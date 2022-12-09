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
    cin >> N >> M;
    NandM(0, N, M);

    return 0;
}

void NandM(int k, int n, int m){
    if(k==m){
        for(int i=0; i<m; i++)
            cout << arr[i] << " ";
        cout << "\n";
        return;
    }

    for(int i=1; i<=n; i++){        
        if(arr[k-1]<i && isUsed[i]==false) //이전에 선택된 값 보다 다음에 선택된 값이 더 크고 방문된 적 없다면
        { 
            arr[k] = i;
            isUsed[i] = true;
            NandM(k+1, n, m);
            isUsed[i] = false;
        }
    }
}