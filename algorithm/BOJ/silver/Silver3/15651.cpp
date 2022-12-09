#include <iostream>
#define MAX_SIZE 8

using namespace std;

int arr[MAX_SIZE];

void NandM2(int k, int n, int m);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);

    int N = 0;
    int M = 0;
    cin >> N >> M;
    NandM2(0, N, M);

    return 0;
}

void NandM2(int k, int n, int m)
{
    if(k==m){
        for(int i=0; i<m; i++){
            cout << arr[i] << " ";
        }
        cout << "\n";
        return ;
    }
    for(int i=1; i<=n; i++) //중복값도 허용하므로 방문체크를 할 필요가 없음
    {
        arr[k] = i;
        NandM2(k+1, n, m);
    }
    
}