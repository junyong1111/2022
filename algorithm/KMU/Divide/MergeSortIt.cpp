#include <iostream>
#define MAX_SIZE 100

using namespace std;

void BuildArray(int *arr, int size);
void CheckArray(int *arr, int size);
void Merge(int *arr, int start, int mid , int end, int size);
void MergeSort(int *arr, int N);
int cntCompare;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("input.txt", "r", stdin);
    int testCase = 0;
    cin >> testCase;

    while(testCase--){
        int size = 0;
        cin >> size;
        int *Arr = new int[size];
        cntCompare = 0;
        BuildArray(Arr, size);
        MergeSort(Arr, size);
        cout << cntCompare << "\n";
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

void Merge(int *arr, int start, int mid , int end, int size){
    int tempArr[size];

    for(int i=start; i<=end; i++)
        tempArr[i] = arr[i];

    int idx = start;
    int i = start;
    int j = mid+1;
    while(i<=mid && j<=end){
        cntCompare++;
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

void MergeSort(int *arr, int N){
    int size = 1;
    while(size <N){
        for(int i=0; i<=N; i+=(2*size)){
            int low = i;
            int mid = (low+(size-1))<(N-1)?(low+(size-1)):(N-1);
            int high = (i+(2*size-1)) <(N-1) ? (i+(2*size-1)):(N-1);
            // CheckArray(arr,N);
            Merge(arr, low, mid, high, N);
        }
        size = size *2;
    }
}