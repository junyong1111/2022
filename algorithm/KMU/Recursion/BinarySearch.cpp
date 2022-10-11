#include <iostream>

using namespace std;

void buildArray(int *Arr, int size);
void checkArray(int *Arr, int size);
int binarySearch(int *Arr, int start , int end, int targetNumber);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("input.txt", "r", stdin);

    int testCase= 0;
    cin >> testCase;

    while(testCase--){
        int size = 0;
        int targetNumber = 0;
        cin >> size >> targetNumber;
        int *Arr = new int;
        buildArray(Arr, size);
        // checkArray(Arr, size);
        cout << binarySearch(Arr,0,size-1,targetNumber) <<"\n";
    }

    return 0;
}

void buildArray(int *Arr, int size){
    for(int i=0; i<size; i++)
        cin >> Arr[i];
}

void checkArray(int *Arr, int size){
    for(int i=0; i<size; i++)
        cout << Arr[i] << " ";
    cout <<"\n";
}

int binarySearch(int *Arr, int start , int end, int targetNumber){
    if(start>end)
        return -1;
    int mid = (start+end)/2;
    if(Arr[mid]==targetNumber)
        return mid;

    else if(Arr[mid]>targetNumber)
        return binarySearch(Arr, start, mid-1, targetNumber);
    else
        return binarySearch(Arr, mid+1, end, targetNumber);
    
}