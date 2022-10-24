#include <iostream>

using namespace std;

void buildArr(int *arr, int size);
void checkArr(int *arr, int size);
void merge(int *arr ,int start, int mid, int end, int sz);
void mergeSort(int *arr, int start, int end, int sz);

int saveCnt;
int TARGET;
int ANSWER;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("input.txt","r",stdin);

    int size = 0;
    int target = 0 ;
    cin >> size >> target;
    TARGET = target;
    int *arr = new int[size];
    buildArr(arr,size);
    mergeSort(arr,0,size-1,size);
    if(saveCnt<TARGET){cout << -1 << "\n";}
    else{cout << ANSWER <<"\n";}
    return 0;
}

void buildArr(int *arr, int size){
    for(int i=0; i<size; i++){
        cin >> arr[i];
    }
}

void checkArr(int *arr, int size){
    for(int i=0; i<size; i++){
        cout << arr[i] << " ";
    }
    cout << "\n";
}

void mergeSort(int *arr, int start, int end, int sz){
    if(start<end){
        int mid = (start+end)/2;
        mergeSort(arr, start, mid,sz);
        mergeSort(arr, mid+1, end,sz);
        merge(arr, start, mid,end,sz);
    }
}


void merge(int *arr ,int start, int mid, int end, int sz){
    int *temp = new int[sz];
    int i = start; //이미 정렬된 좌측
    int j = mid+1; // 이미 정렬된 우측부터 
    int idx = start; // 정렬된 좌측부터 시작

    while(i<=mid && j<=end ){
        if(arr[i]<arr[j]){
            saveCnt++;
            if(TARGET == saveCnt)
                ANSWER = arr[i];
            temp[idx++] = arr[i++];
        }
        else {
            saveCnt++;
            if(TARGET == saveCnt)
                ANSWER = arr[j];
            temp[idx++] = arr[j++];
        }
    }

    while(i<=mid){
        saveCnt++;
        if(TARGET == saveCnt)
            ANSWER = arr[i];
        temp[idx++] = arr[i++];
    }

    while(j<=end){
        saveCnt++;
        if(TARGET == saveCnt)
            ANSWER = arr[j];
        temp[idx++] = arr[j++];
    }

    for(int i=start; i<=end; i++){
        arr[i] = temp[i];
    }

    delete[] temp;
}