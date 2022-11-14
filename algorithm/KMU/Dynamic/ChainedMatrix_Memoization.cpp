#include <iostream>
#define MAX_SIZE 101
#define INF 2100000000
#define MIN(a,b) ((a)>(b)?(b):(a))
using namespace std;

int memo[MAX_SIZE][MAX_SIZE];

void BuildArray(int *arr, int size);
void CheckArray(int *arr, int size);
int MatrixChain_Memoization(int *arr, int i, int j);
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
        BuildArray(arr,size+1);
        init();
        int answer = MatrixChain_Memoization(arr, 1, size);
        cout << answer << "\n";
    
    }
    return 0;
}

void BuildArray(int *arr, int size){
    for(int i=0; i<size; i++)
        cin >> arr[i];
}
void CheckArray(int *arr, int size){
    for(int i=0; i<size; i++)
            cout << arr[i] << " ";
        cout <<"\n";
}

int MatrixChain_Memoization(int *arr, int i, int j)
{
    if (i == j)
        return 0;
    if(memo[i][j]!=-1)
        return memo[i][j];
    int k = 0;
    int min = INF;
    memo[i][j] = min;
    for (int k = i; k < j; k++)
    {
        int left = memo[i][j];
        int right = MatrixChain_Memoization(arr, i, k) + MatrixChain_Memoization(arr, k + 1, j)
                    + arr[i - 1] * arr[k] * arr[j];
        memo[i][j] = MIN(left, right);
    }

    return memo[i][j];
}
 

void init(){
    for(int i=0; i<MAX_SIZE; i++){
        for(int j=0; j<MAX_SIZE; j++){
            memo[i][j] = -1;
        }
    }
}