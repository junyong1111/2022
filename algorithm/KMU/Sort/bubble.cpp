#include <iostream>
#define MAX_SIZE 1000

using namespace std;

void swap(int* a, int* b);
void CoppyArray(int A[], int B[], int Size);
void BubbleSrot(int A[], int Size);
void BubbleSortImproved1(int A[], int Size);
void BubbleSortImproved2(int A[], int Size);

int main(){
    // freopen("input.txt", "r", stdin);

    int testCase = 0;
    cin >> testCase;

    while(testCase--){
        int Size = 0;
        cin >> Size;
        int Arr[MAX_SIZE] = {0};
        int CoppyArr1[MAX_SIZE] = {0};

        for(int i=0; i<Size; i++){
            cin >> CoppyArr1[i] ;
        }
        CoppyArray(Arr,CoppyArr1,Size);
        BubbleSrot(Arr, Size);
        
        CoppyArray(Arr,CoppyArr1,Size);
        BubbleSortImproved1(Arr, Size);
        
        CoppyArray(Arr,CoppyArr1,Size);
        BubbleSortImproved2(Arr, Size);

        cout << "\n";


    }



    return 0;
}

void CoppyArray(int A[], int B[], int Size){
    for(int i=0; i<Size; i++){
        A[i]=  B[i] ;
    }
}

void BubbleSrot(int A[], int Size){
    int countCmpOps = 0; // 비교 연산자 실행 횟수 
    int countSwaps = 0; // swap 함수 실행 횟수
    for(int i=0; i<Size; i++){
        for(int j=1; j<Size-i; j++){
            if(A[j-1]>A[j]){
                swap(A[j-1],A[j]);
                countSwaps++;
            }
            countCmpOps ++;
            
        }
    }

    cout << countCmpOps << " " << countSwaps << " ";

}

void BubbleSortImproved1(int A[], int Size){
    int countCmpOps = 0; // 비교 연산자 실행 횟수 
    int countSwaps = 0; // swap 함수 실행 횟수
    for(int i=0; i<Size; i++){
        bool check = false;
        for(int j=1; j<Size-i; j++){
            if(A[j-1]>A[j]){
                swap(A[j], A[j-1]);
                countSwaps ++;
                check = true;
            }
            countCmpOps ++;
        }
        if(check == false){break;} //데이터를 교환하지 않았으면 이미 데이터는 정렬된 상태이다.
    }

    cout << countCmpOps << " " << countSwaps << " ";
}

void BubbleSortImproved2(int A[], int Size){
    int countCmpOps = 0; // 비교 연산자 실행 횟수 
    int countSwaps = 0; // swap 함수 실행 횟수
    int LastSwapPos = Size;

    while(LastSwapPos > 0){
        int SwapPos = 0;
        for(int i=1; i< LastSwapPos; i++){
            countCmpOps++;
            if(A[i-1] > A[i]){
                swap(A[i], A[i-1]);
                countSwaps ++;
                SwapPos = i;
               
            }
        }
        
        LastSwapPos = SwapPos;
    }

    cout << countCmpOps << " " << countSwaps << " ";

}

void swap(int* a, int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp; 
}