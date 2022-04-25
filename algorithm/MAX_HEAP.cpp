#include <iostream>

int Arr[] = {1,28,52};
int SIZE = 3;

using namespace std;

void p(){
    for(int i=0; i<SIZE; i++){
        cout << Arr[i] << " " ;
    }
    cout << endl;
}


void BUILD_HEAP(int A[], int K){
    int L = (K*2) +1;
    int R = L+1>=SIZE?0:L+1;
    int Max = 0;
    if(L>=SIZE)
        cout << "Empty child Node\n";
    else{
        Max = A[L]<=A[R]?R:L;
        if(A[K] <=A[Max]){
            int temp = A[Max];
            A[Max] = A[K];
            A[K] = temp;
            BUILD_HEAP(A,Max);
        }
    }
}
void MAX_HEAPIPY(int A[], int SZ){
    int L = 0;
    int R = 0;
    int Max = 0;
    for(int i = (SZ-1)/2; i>=0; i--){
        
        L = (i*2)+1;
        cout << "CURR L :" << L <<"\n";
        cout << "CURR A[L] :" << A[L] <<"\n";
        R = L+1>=SIZE?0:L+1;
        if(R==0)
            Max = L;
        else 
            Max = A[L]<=A[R]?R:L;
        if(A[i]<=A[Max]){
            int temp = A[Max];
            A[Max] = A[i];
            A[i] = temp;
            BUILD_HEAP(A,Max);
        }
    }
}

int main(){
    // p();
    MAX_HEAPIPY(Arr, SIZE);
    // p();

    
    return 0;
}