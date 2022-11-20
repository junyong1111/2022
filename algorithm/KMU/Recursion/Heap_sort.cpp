#include <iostream>

using namespace std;

void BuildArray(int *arr, int size);
void HeapSort(int *arr, int size);
void FixHeap(int *arr, int size, int root, int k);

int Count ;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("input.txt", "r", stdin);
    
    int testCase = 0;
    cin >> testCase;

    while(testCase--) {
        int size = 0;
        cin >> size;
        int *arr = new int[size+1];
        for(int i=1; i<=size; i++){
            cin >> arr[i];
        }
        Count = 0;
        HeapSort(arr, size);
        cout << Count << endl;
    }
}

void HeapSort(int *arr, int size) {
    int heapSize;
    
    for (int i = size/2; i >= 1; i--) 
        FixHeap(arr, size, i, arr[i]);

    for (heapSize = size; heapSize >= 2; heapSize--) {
        int max = arr[1];
        FixHeap(arr, heapSize-1, 1,arr[heapSize]);
        arr[heapSize] = max;
    }
} 

void FixHeap(int *arr, int size, int root, int k){
    int node = root;
    int largerChild;
    while((arr[node * 2] != 0 && node * 2 <= size) || (arr[node * 2 + 1] != 0 && node * 2 + 1 <= size)) {
        if(arr[node * 2 + 1] != 0 && node * 2 + 1 <= size) {
			if(arr[node * 2] < arr[node * 2 + 1]) {
				largerChild = node * 2 + 1;
			} else {
				largerChild = node * 2;
			}
            Count += 2;
		} else {
			Count += 1;
			largerChild = node * 2;
		}
        if (k < arr[largerChild]) {
            arr[node] = arr[largerChild];
            node = largerChild;
        }
        else {
            break;
        }
    }
    arr[node] = k;
}

void BuildArray(int *arr, int size){
    for(int i=1; i<=size; i++){
        cin >> arr[i];
    }
}