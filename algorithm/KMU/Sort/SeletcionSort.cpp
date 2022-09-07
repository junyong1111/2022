#include <iostream>
#define MAX_SIZE 1000

using namespace std;

void selectionSort(int A[], int Sz);
void swap(int* a, int* b);


int main(void){
    freopen("input.txt", "r", stdin);

    int testCase = 0;
    cin >> testCase;

    while(testCase--){
        int Sz = 0;
        int A[MAX_SIZE] ={0};
        cin >> Sz;
        

        for(int i=0; i<Sz; i++)
            cin >> A[i];
        selectionSort(A,Sz);

    }

    return 0;
}

void selectionSort(int A[], int Sz){
    int countCmpOps = 0;
    int countSwaps = 0;

    int minValue = 0;
    for(int i=0; i<Sz; i++){
        minValue = i;
        for(int j=i+1; j<Sz; j++){
            countCmpOps++;
            if(A[minValue] > A[j]){
                minValue = j;
            }
        }
    if(minValue!=i){
        swap(A[minValue], A[i]);
        countSwaps++;
     }
    }
    cout << countCmpOps << " " << countSwaps <<"\n";
}


void swap(int* a, int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp; 
}

