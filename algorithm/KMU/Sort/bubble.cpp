#include <iostream>

using namespace std;


void CoppyArray(int A[], int B[], int Size);
void BubbleSrot(int A[], int Size);
void BubbleSortImproved1(int A[], int Size);
void BubbleSortImproved2(int A[], int Size);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);

    int testCase = 0;
    cin >> testCase;

    while(testCase--){
        int Size = 0;
        cin >> Size;
        int Arr[Size] = {0};
        int CoppyArr1[Size] = {0};
        int CoppyArr2[Size] = {0};

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
                int temp = A[j];
                A[j] = A[j-1];
                A[j-1] = temp;
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
                int temp = A[j];
                A[j] = A[j-1];
                A[j-1] = temp;
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
                int temp = A[i];
                A[i] = A[i-1];
                A[i-1] = temp;
                swapCnt ++;
                SwapPos = i;
               
            }
        }
        
        LastSwapPos = SwapPos;
    }

    cout << cnt << " " << swapCnt << " ";

}