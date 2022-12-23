#include <iostream>
#define MAX_SIZE 501
#define INF 2100000000
#define MIN(a,b) ((a)<(b)?(a):(b))

using namespace std;

int MatrixChain_DP(int *arr, int N);
int M[MAX_SIZE][MAX_SIZE];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r" ,stdin);

    int N = 0;
    cin >> N;

    int *arr = new int[N+1];
    int a = 0;
    int b = 0;
    cin >> arr[0] >> arr[1];
    
    for(int i=1; i<N; i++){
        a = 0;
        b = 0;
        cin >> a >> b;
        arr[i+1] = b;
    }

    int answer = MatrixChain_DP(arr,N);
    cout << answer << "\n";

    return 0;
}

int MatrixChain_DP(int *arr, int N)
{
    int i,j,d;
    for(int i=0; i<=N; i++){
        for(int j=0; j<=N; j++)
            M[i][j] = INF;
    }

    for(int i=1; i<=N; i++){
        M[i][i] = 0;
    }

    int cost = 0;
    int min = 0;

    for(d=1; d<=N-1; d++)
    {
        for(i=1; i<=N-d; i++)
        {
            j= d+i;
            for(int k=i; k<=j-1; k++){
                cost = M[i][k] + M[k+1][j] +  arr[i-1]*arr[k]*arr[j];
                if(cost < M[i][j]){
                    M[i][j] = cost;
                    min = k;
                }
            }
        }
    }
    return M[1][N];
}