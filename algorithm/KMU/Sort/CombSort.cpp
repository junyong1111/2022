#include <iostream>
#include <cmath>

#define MAX_SIZE 1000

using namespace std;

void CombSort(int A[], int Sz);
void swap(int* a, int* b);

int main(void){
    // freopen("input.txt", "r", stdin);

    int testCase = 0 ;
    cin >> testCase;

    while(testCase--){
        int Sz = 0;
        int A[MAX_SIZE];
        cin >> Sz;

        for(int i=0; i<Sz; i++)
            cin >> A[i];
        CombSort(A,Sz);
    }

    return 0;
}


void CombSort(int A[], int Sz){
    int countCmpOps = 0; // 비교 연산자 실행 횟수 
    int countSwaps = 0;
    int gap = Sz;
    double shrink = 1.3;
    bool sorted = false;

    while(sorted ==false){
        gap = floor(gap/shrink);
        if(gap <=1){
            gap = 1;
            sorted = true;
        }
        
            int i = 0;
            while(i+gap < Sz){
                countCmpOps++;
                if(A[i] > A[i+gap]){
                    swap(A[i], A[i+gap]);
                    countSwaps++;
                    sorted = false;
                }
                
                i++;
            }
        
    }

    cout << countCmpOps << " " <<  countSwaps <<"\n";
} 

void swap(int* a, int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp; 
}