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
        int CoppyArr2[MAX_SIZE] = {0};

        for(int i=0; i<Size; i++){
            cin >> Arr[i] ;
        }
        CoppyArray(Arr,CoppyArr1,Size);
        CoppyArray(Arr,CoppyArr2,Size);

        BubbleSrot(Arr, Size);
        BubbleSortImproved1(CoppyArr1, Size);
        BubbleSortImproved2(CoppyArr2, Size);
        cout << endl;



    }



    return 0;
}

void CoppyArray(int A[], int B[], int Size){
    for(int i=0; i<Size; i++){
        B[i] = A[i];
    }
}

void BubbleSrot(int A[], int Size){
    int cnt = 0;
    int swapCnt = 0;
    for(int i=0; i<Size; i++){
        int com = A[0];
        for(int j=1; j<Size-i; j++){
            if(com>A[j] ){
                swap(A[j], A[j-1]);
                swapCnt ++;
            }
            cnt ++;
            com = A[j];
        }
    }

    cout << cnt << " " << swapCnt << " ";

}

void BubbleSortImproved1(int A[], int Size){
    int cnt = 0;
    int swapCnt = 0;
    for(int i=0; i<Size; i++){
        bool check = false;
        int com = A[0];
        for(int j=1; j<Size-i; j++){
            if(com>A[j] ){
                swap(A[j], A[j-1]);
                swapCnt ++;
                com = A[j];
                check = true;
            }
            cnt ++;
        }
        if(check == false){break;} //데이터를 교환하지 않았으면 이미 데이터는 정렬된 상태이다.
    }

    cout << cnt << " " << swapCnt << " ";
}

void BubbleSortImproved2(int A[], int Size){
    int cnt = 0;
    int swapCnt = 0;
    int LastSwapPos = Size;

    while(LastSwapPos > 0){
        int SwapPos = 0;
        for(int i=1; i< LastSwapPos; i++){
            cnt++;
            if(A[i-1] > A[i]){
                swap(A[i], A[i-1]);
                swapCnt ++;
                SwapPos = i;
               
            }
        }
        
        LastSwapPos = SwapPos;
    }

    cout << cnt << " " << swapCnt << " ";

}

void swap(int* a, int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp; 
}