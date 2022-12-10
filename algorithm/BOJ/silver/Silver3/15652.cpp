#include <iostream>
#define MAX_SIZE 9

using namespace std;

int arr[MAX_SIZE];


void NandM_4(int k, int n, int m);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);

    int N = 0;
    int M = 0;
    cin >> N >> M;
    NandM_4(0, N, M);

    return 0;
}
void NandM_4(int k, int n, int m)
{
    if(k==m){
        for(int i=0; i<m; i++){
            cout << arr[i] << " ";
        }
        cout << "\n";
        return ;
    }

    for(int i=1; i<=n; i++){ // 오름차순으로 정렬해야 하므로 이전에 들어간 값보다 다음값이 크다면 진행
        if(arr[k-1]<=i)
        {
            arr[k] = i;
            NandM_4(k+1, n, m);
        }
    }

}