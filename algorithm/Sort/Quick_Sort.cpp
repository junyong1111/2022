#include <iostream>
#include <ctime>

using namespace std;


int Quick_partition(int arr[], int start, int end){
    srand(time(NULL));
    //int p_idx = rand()%end;
    int p = arr[end]; // Pivot을 랜덤값으로 지정
    int i = start-1; //배열의 밖을 지정
    int j = start; // 시작 부분 지정

    while(j<end)
    {
    if(arr[j]>=p) 
        j = j+1;  // 기준보다 크면 그냥 넘어감 
    else{  //기준보다 작다면 값을 스왑
        i = i+1;
        int temp = arr[j];
        arr[j] = arr[i];
        arr[i] = temp;
        j = j+1;
        }
    }
    int temp = arr[i+1];  //마지막 기준값을 위치에 맞게 재배치 이후 Index를 return
    arr[i+1] = p;
    arr[end] = temp;
    return (i+1);
}

void Quick_Sort(int arr[], int start, int end){
    if(start<end){
        int pivot = Quick_partition(arr, start, end);
        Quick_Sort(arr,start, pivot-1);
        Quick_Sort(arr, pivot+1, end);
    }
}
int main(){
    int arr[] = {12,24,63,12,51,2,125,32};
    int size = 8;
    int start = 0;
    int end = size-1;
    Quick_Sort(arr,start, end);
    
    for(int i=0; i<=end; i++)
        cout << arr[i] << " ";
    cout << "\n";
    return 0;
}