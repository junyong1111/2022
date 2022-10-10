#include <iostream>
using namespace std;

void bulidList(int *arr, int size);
void checkList(int *arr, int size);
void mergeSort(int *arr, int start, int end, int size);
void merge(int *arr, int start, int mid , int end, int size,int target);
int cnt;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("input.txt", "r", stdin);

    // int testCase = 0;
    // cin >> testCase;
    
    // while(testCase--){
        int * arr = new int;
        int size = 0;
        int targetNum = 0;
        cnt = 0;
        cin >> size  >> targetNum;
        bulidList(arr,size);
        mergeSort(arr,0, size-1, size,targetNum);
        // checkList(arr,size);
    // }


    return 0;
}

void bulidList(int *arr, int size){
    for(int * temp = arr; temp<arr+size; temp++){
        int num = 0;
        cin >> num;
        *temp = num;
    }
}

void checkList(int *arr, int size){
    for(int * temp = arr; temp<arr+size; temp++){
        cout << *temp  << " ";
    }
    cout << "\n";
}

void merge(int *arr, int start, int mid , int end, int size, int target){
    int tempArr[size];

    for(int i=start; i<=end; i++)
        tempArr[i] = arr[i];

    int idx = start;
    int i = start;
    int j = mid+1;
    while(i<=mid && j<=end){
        cnt++;
        if(cnt == target){
            
        }
        if(tempArr[i] <= tempArr[j]){
            arr[idx++] = tempArr[i++]; 
        }
            
        else
            arr[idx++] = tempArr[j++];
    }
    while(i<=mid)
        arr[idx++] = tempArr[i++];
    while(j<=end)
        arr[idx++] = tempArr[j++];
}

void mergeSort(int *arr, int start, int end, int size){
    if(start == end){
        return ;
    }
    else{
        int mid = (start+end) /2;
        mergeSort(arr, start, mid,size);
        mergeSort(arr,mid+1, end,size);
        merge(arr ,start , mid, end, size);
    }

}