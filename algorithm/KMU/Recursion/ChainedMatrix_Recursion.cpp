#include <iostream>
#define INF 2100000000
#define MIN(a,b) ((a)>(b)?(b):(a))
using namespace std;

void BuildArray(int *arr, int size);
void CheckArray(int *arr, int size);
int MatrixChain_Recurion(int *arr, int i, int j);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);

    int testCase = 0;
    cin >> testCase;
    while(testCase--){
        int size = 0;
        cin >> size ;
        int *arr = new int[size+1];
        BuildArray(arr,size+1);
        int answer = MatrixChain_Recurion(arr, 1, size);
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

int MatrixChain_Recurion(int *arr, int i, int j)
{
    if (i == j)
        return 0;
    int k = 0;
    int min = INF;
    int count;
 
    for (k = i; k < j; k++)
    {
        count = MatrixChain_Recurion(arr, i, k) + MatrixChain_Recurion(arr, k + 1, j) 
        + arr[i - 1] * arr[k] * arr[j];
        min = MIN(count, min);
    }

    return min;
}
 