#include <iostream>
#define MAX_SIZE 1000

using namespace std;

void InsertionSort(int A[], int sz);

int main(){
    // freopen("input.txt", "r" ,stdin);
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
        int temp = A[i];
        int j = i-1;
        for(; j>=0; j--){
            countCmpOps++;
            if(temp<A[j]){
                A[j+1] = A[j];
                countSwaps++;
            }else{
                break;
            }
        }
        A[j+1] = temp;
        
    }
    printf("%d %d ", countCmpOps, countSwaps);
}
