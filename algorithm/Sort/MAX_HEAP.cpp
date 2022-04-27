#include <iostream>
#include <vector>

using namespace std;


void MAX_HEAPIPY(int arr[], int N, int sz)
{
    int left = (N*2) +1;
    int right = left +1;
    int max = 0;
    if(left>=sz){ //자식이 없는경우
        ;
    }
    else{
        if(right>=sz){
            right = 0;
            max = left;
        } //우측 노드가 없는경우 
        else{
            max = arr[left]<=arr[right]?right:left;
        }
        if(arr[N]<= arr[max]){
            int temp = arr[max];
            arr[max] = arr[N];
            arr[N] = temp;
            MAX_HEAPIPY(arr,max,sz); //반복
        }
    }
}

void HEAP_BUILD(int arr[], int sz){
    int len = sz;
    for(int i=(len/2)-1; i>=0; i--){
        MAX_HEAPIPY(arr,i,sz); //i는 원하는 노드 
    }
}

void Heap_Sort(int arr[], int sz)
{   
    if(sz==1){
        cout << "ROOT\n";
    }
    else{
    int len = sz-1;
    int temp = arr[0];
    arr[0] = arr[len];
    arr[len] = temp;
    MAX_HEAPIPY(arr,0,);
    Heap_Sort(arr, len);
    }

}

int main(){
    int A[] = {12,24,63,14,51,2,125,32};
    int len = sizeof(A)/sizeof(int);
    HEAP_BUILD(A,len);
    for(int i=0; i<len; i++){
        cout << A[i] << " " ;
    }
    cout << "\n";

    Heap_Sort(A,len);
    for(int i=0; i<len; i++){
        cout << A[i] << " " ;
    }
    cout << "\n";

    return 0;
}