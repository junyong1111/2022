#include <iostream>
#define MAX_SIZE 1000

using namespace std;

void InsertionSort(int A[], int sz);
void swap(int* a, int* b);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r" ,stdin);

    int testCase = 0;
    cin >> testCase;

    while(testCase--){
        int sz = 0;
        int A[MAX_SIZE];
        cin >> sz;

        for(int i=0; i<sz; i++)
            cin >> A[i];
        InsertionSort(A, sz);
        cout << "\n";
    }

    return 0;
}

void InsertionSort(int A[], int sz)
{
    int countCmpOps = 0; // 비교 연산자 실행 횟수 
    int countSwaps = 0; // swap 함수 실행 횟수

    for(int i =1; i<sz; i++){
        int com = A[i];
        for(int j=i-1; j>=0; j--){
            countCmpOps++;
            if(com<A[j]){
                countSwaps++;
                swap(A[j], A[j+1]);
            }
            else{break;}
        }
    }
    printf("%d %d ", countCmpOps, countSwaps);
}

void swap(int* a, int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp; 
}