#include <iostream>

using namespace std;

void BuildArray(int *arr, int size);
void CheckArray(int *arr, int size);
void Swap(int *Arr, int a, int b);
void CoppyArray(int *a, int *b, int size);
void QuickSortHoare(int *arr, int low, int high);
int PartitionHoare(int *arr, int low, int high);
void QuickSortRomuto(int *arr, int low, int high);
int PartitionRomuto(int *arr, int low, int high);

int cntSwapRomuto;
int cntCompareRomuto;
int cntSwapHoare;
int cntCompareHoare;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("input.txt","r", stdin);

    int testCase = 0; 
    cin >> testCase;

    while(testCase--){
        int size = 0;
        cin >> size ;
        int *Arr1 = new int[size];
        int *Arr2 = new int[size];
        cntSwapRomuto = 0;
        cntCompareRomuto = 0;
        cntSwapHoare = 0; 
        cntCompareHoare = 0;

        BuildArray(Arr1,size);
        CoppyArray(Arr1, Arr2, size);
        QuickSortHoare(Arr1, 0,size-1);
        QuickSortRomuto(Arr2, 0,size-1);
        // CheckArray(Arr1, size);
        // CheckArray(Arr2, size);
        cout << cntSwapHoare << " "<< cntSwapRomuto << " " << cntCompareHoare << " " << cntCompareRomuto << "\n";

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

void Swap(int *Arr, int a, int b){
    int temp = Arr[a];
    Arr[a] = Arr[b];
    Arr[b] = temp;
}

void CoppyArray(int *a, int *b, int size){
    for(int i=0; i<size; i++)
        b[i] = a[i];
}


void QuickSortHoare(int *arr, int low, int high){ 
    if (low >= high)
        return ;
    int pos = PartitionHoare(arr, low,high);
    QuickSortHoare(arr, low, pos);
    QuickSortHoare(arr, pos+1, high);
    

}
int PartitionHoare(int *arr, int low, int high){ // i와 j가 반대 방향에서 중앙으로 증가와 감소
    int pivot = arr[low];
    int i = low -1;
    int j = high+1;
    while(1){
        cntCompareHoare++;
        while(arr[++i] < pivot){
            cntCompareHoare++;
            continue;
        }
        cntCompareHoare++;
        while(arr[--j]>pivot){
            cntCompareHoare++;
            continue;
        }
        if(i<j){
            Swap(arr, i,j);
            cntSwapHoare++;
        }
        else
            return j;
    }
}

void QuickSortRomuto(int *arr, int low, int high){
    if (low >= high)
        return ;
    int pos = PartitionRomuto(arr, low,high);
    QuickSortRomuto(arr, low, pos-1);
    QuickSortRomuto(arr, pos+1, high);

}

int PartitionRomuto(int *arr, int low, int high){ // i와 j가 한 방향에서 같이 증가
    int pivot = arr[low]; //제일 왼쪽 원소를 pivot으로 설정
    int i = low+1;
    int j = low;

    for(; i<=high; i++){
        cntCompareRomuto++;
        if(arr[i] <pivot){ //지정한 pivot보다 현재 값이 더 작은 경우
            j++; //j를 한 칸 증가 후 swap
            Swap(arr, i,j);
            cntSwapRomuto++;
        }
    }
    int pivotPos = j; // 위 과정을 끝낸 후 pivot과 마지막 j인덱스를 swap
    Swap(arr, pivotPos, low);
    cntSwapRomuto++;
    return pivotPos;
}