#include <iostream>
#define MAX_SIZE 1000

using namespace std;

void ShellSort(int A[], int Sz);

int main(void){
    // freopen("input.txt", "r", stdin);

    int testCase = 0;
    cin >> testCase;

    while(testCase--){
        int Sz = 0;
        int A[MAX_SIZE] ={0};
        cin >> Sz;
        for(int i=0; i<Sz; i++)
            cin >> A[i];
        ShellSort(A,Sz);
    }
    return 0;
}

void ShellSort(int A[], int Sz){
    int countCmpOps = 0;
    int countSwaps = 0;

    int shrink_ratio = 2;
    int gap = Sz/shrink_ratio;
    
    while(gap>0){

        for(int i=gap; i<Sz; i++){
            int temp = A[i];
            int j = i;
            for(; j>=gap; j -= gap){
                countCmpOps++;
                if(A[j-gap] > temp){
                    A[j] = A[j-gap];
                    countSwaps++;
                }
                else{break;}    
            }
             A[j] = temp;

        }
        gap = gap/shrink_ratio;
    }
    cout << countCmpOps << " " << countSwaps <<"\n";
}


