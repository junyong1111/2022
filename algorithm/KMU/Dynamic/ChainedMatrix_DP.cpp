#include <iostream>
#define INF 2100000000
#define MAX_SIZE 102
#define MIN(a,b) ((a)>(b)?(b):(a))
using namespace std;

int dp[MAX_SIZE][MAX_SIZE];

void BuildArray(int *arr, int size);
int MatrixChain_DP(int *arr, int N);
void Order(int i, int j);
void init();


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("input.txt", "r", stdin);

    int testCase = 0;
    cin >> testCase;
    while(testCase--){
        int size = 0;
        cin >> size ;
        int *arr = new int[size+1];
        BuildArray(arr,size);
        int answer = MatrixChain_DP(arr,size);
        Order(1,size);
        cout << "\n";
        cout << answer << "\n";
        init();
    }
    return 0;
}

void BuildArray(int *arr, int size){
    for(int i=0; i<=size; i++)
        cin >> arr[i];
}

int MatrixChain_DP(int *arr, int N)
{
    int i,j,k,diagonal;
    int M[N+1][N+1];
    for(i=0; i<=N; i++)
        for(j=0; j<=N; j++)
            M[i][j] =INF;
    int cost = 0;
    int min = 0;


    for(i=1; i<=N; i++)
        M[i][i] = 0;

    for(diagonal=1; diagonal<=N-1; diagonal++){
        for(i=1; i<=N-diagonal; i++){
            j = i+diagonal;

            for(k=i; k<= j-1; k++){
                cost = M[i][k] + M[k+1][j] + arr[i-1]*arr[k]*arr[j];
                if(cost<M[i][j]){
                    M[i][j] = cost;
                    min = k;
                }
            }
            dp[i][j] = min;
        }
    }
    return M[1][N];
}
 
void Order(int i, int j){
    int k;
    if(i==j)
        cout << "M" <<i;
    else{
        k = dp[i][j];
        cout << "(";
        Order(i,k);
        Order(k+1,j);
        cout << ")";
    }
}

void init(){
    for(int i=0; i<MAX_SIZE; i++){
        for(int j=0; j<MAX_SIZE; j++){
            dp[i][j] = 0;
        }
    }
}